import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import math


def point_to_line_distance(P, A, B):
    # P = np.array(P)
    # A = np.array(A)
    # B = np.array(B)

    AB = B - A
    AP = P - A

    distance = np.abs(np.cross(AB, AP)) / np.linalg.norm(AB)
    return distance

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

p1 = np.array([1.4, 1.5])
p2 = np.array([2.5, 7])

plt.plot([p1[0], p2[0]], [p1[1], p2[1]], linewidth=3)
plt.scatter([p1[0], p2[0]], [p1[1], p2[1]], color=[0.6, 0.2, 0.8], s=100, zorder=3)


# print(p1[0], p2[0])
# print(np.sort([p1[0], p2[0]]))
# print(row_sorted)
# print(math.floor(row_sorted[0] + 0.5), math.floor(row_sorted[1] + 0.5))

# col_sorted = np.array([p1[0], p2[0]])
# row_sorted = np.array([p1[1], p2[1]])

if p1[1] > p2[1]:
	grid_row = [math.floor(p1[1] + 0.49), math.floor(p2[1] + 0.51)]
else:
	grid_row = [math.floor(p1[1] + 0.51), math.floor(p2[1] + 0.49)]

if p1[0] > p2[0]:
	grid_col = [math.floor(p1[0] + 0.49), math.floor(p2[0] + 0.51)]
else:
	grid_col = [math.floor(p1[0] + 0.51), math.floor(p2[0] + 0.49)]


grids = np.array([grid_row, grid_col])
# data[[grids[0,0], grids[1,0]], [grids[0,1], grids[1,1]]] = 2.0
# print([grids[0,0]: grids[1,0], grids[0,1]: grids[1,1]])
# col_sort_rounded = np.array([math.floor(col_sorted[0] + 0.51), math.floor(col_sorted[1] + 0.49)])

# row_sort_rounded = np.array([math.floor(row_sorted[0] + 0.51), math.floor(row_sorted[1] + 0.49)])

# for i in range(row_sort_rounded[0], row_sort_rounded[1]+1):
# 	for j in range(col_sort_rounded[0], col_sort_rounded[1]+1):
# data[row_sort_rounded[0]:row_sort_rounded[1]+1, col_sort_rounded[0]:col_sort_rounded[1]+1] = 2.0


x0, y0 = grids[0]
x1, y1 = grids[1]

dx = abs(p2[0] - p1[0])
dy = abs(p2[1] - p1[1])

# sx = 1 if x1 > x0 else (-1 if x1 < x0 else 0)
# sy = 1 if y1 > y0 else (-1 if y1 < y0 else 0)

sx = 1 if x1 > x0 else -1
sy = 1 if y1 > y0 else -1

err = dx - dy

print(grids)
print(grids[0])

while True:
    data[y0, x0] = 2.0

    if x0 == x1 and y0 == y1:
        break

    e2 = 2 * err

    ey = e2 + dy
    ex = e2 - dx

    if e2 > -dy:
        err -= dy
        x0 += sx

    if e2 < dx:
        err += dx
        y0 += sy
    print([x0, y0])











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