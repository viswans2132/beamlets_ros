import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import math


def side_of_line(pt, A, B):
    x, y = pt
    xA, yA = A
    xB, yB = B
    return (x - xA) * (yB - yA) - (y - yA) * (xB - xA)

def line_touches_box(A, B, pt, box_size):
    xmin, xmax = pt[0] - box_size/2, pt[0] + box_size/2
    ymin, ymax = pt[1] - box_size/2, pt[1] + box_size/2
    c00 = (xmin, ymin)
    c11 = (xmax, ymax)
    c01 = (xmin, ymax)
    c10 = (xmax, ymin)

    s00 = side_of_line(c00, A, B)
    s11 = side_of_line(c11, A, B)
    s01 = side_of_line(c01, A, B)
    s10 = side_of_line(c10, A, B)

    return (s00 * s11 <= 0) or (s01 * s10 <= 0)

cmap = ListedColormap(['black', 'gray', 'white', 'red'])

# ---- PARAMETERS ----
A = 6          # figure size (in inches)
rows, cols = 10, 10

# ---- DATA ----
# data = np.random.rand(rows, cols)
data =  np.ones((rows, cols))

# data[-1,-1] = 0.0

# ---- FIGURE ----
plt.figure(figsize=(A, A))
ax = plt.gca()   # get current axes
# ---- PLOT ----

p1 = np.array([1.5, 7.5])
p2 = np.array([5.5, 7.5])

plt.plot([p1[0], p2[0]], [p1[1], p2[1]], linewidth=3)
plt.scatter([p1[0], p2[0]], [p1[1], p2[1]], color=[0.6, 0.2, 0.8], s=100, zorder=3)

if p1[1] > p2[1]:
	grid_row = [math.floor(p1[1] + 0.49), math.floor(p2[1] + 0.51)]
else:
	grid_row = [math.floor(p1[1] + 0.51), math.floor(p2[1] + 0.49)]

if p1[0] > p2[0]:
	grid_col = [math.floor(p1[0] + 0.49), math.floor(p2[0] + 0.51)]
else:
	grid_col = [math.floor(p1[0] + 0.51), math.floor(p2[0] + 0.49)]


grids = np.array([grid_row, grid_col]).T


x0, y0 = grids[0]
x1, y1 = grids[1]

dx = abs(p2[0] - p1[0])
dy = abs(p2[1] - p1[1])

sx = 1 if x1 > x0 else -1
sy = 1 if y1 > y0 else -1

err = dx - dy

row_sorted = np.sort(grids[:,0])
col_sorted = np.sort(grids[:,1])

for row in range(row_sorted[0], row_sorted[1]+1):
	for col in range(col_sorted[0], col_sorted[1]+1):
		grid_point = np.array([col, row])

		if line_touches_box(p1, p2, grid_point):
			data[row, col] = 2.0




ax.imshow(data, cmap=cmap, vmin=0, vmax=2)

# ---- GRID LINES ----
ax.set_xticks(np.arange(-0.5, cols, 1), minor=True)
ax.set_yticks(np.arange(-0.5, rows, 1), minor=True)
ax.grid(which='minor', linestyle='-', linewidth=1)

ax.tick_params(which='minor', bottom=False, left=False)

# ---- CLEANUP ----
ax.set_xticks([])
ax.set_yticks([])
ax.set_aspect('equal')

plt.show()