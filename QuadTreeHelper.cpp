#include "QuadTreeHelper.h"
#include "config.h"

int QuadTreeHelper::countObstacles(int s, int x, int y) const
{
    int size = pow(2, s);
    
    int rowStart = (x-1)*size;  // x -> row
    int colStart = (y-1)*size;  // y -> column

    int count = 0;

    for(int i=rowStart; i<rowStart+size; i++)
        for(int j=colStart; j<colStart+size; j++)
            if(i >= 0 && i < Config::grid.size() && j >= 0 && j < Config::grid[0].size() && Config::grid[i][j] == 1)
                count++;

    return count;
}

void QuadTreeHelper::printQuadTree(QuadTreeNode* node, int depth) const
{
    if(!node) return;

    for(int i=0;i<depth;i++)
        cout<<"   ";

    cout<<"q("<<node->s<<";"<<node->x<<","<<node->y<<") -> "
        <<node->color
        <<" (obs="<<node->obstacleCount<<")"<<endl;

    for(int i=0;i<4;i++)
        printQuadTree(node->children[i],depth+1);
}

void QuadTreeHelper::printFormalDyadicForm(QuadTreeNode* node) const
{
    if(!node) return;

    if(node->children[0] == nullptr)
    {
        cout<<"q("<<node->s<<";"<<node->x<<","<<node->y<<") = "
            <<node->color<<endl;
        return;
    }

    cout<<"q("<<node->s<<";"<<node->x<<","<<node->y<<") = ";
    cout<<"q("<<node->s-1<<";"<<2*node->x-1<<","<<2*node->y-1<<") ∪ ";
    cout<<"q("<<node->s-1<<";"<<2*node->x-1<<","<<2*node->y<<") ∪ ";
    cout<<"q("<<node->s-1<<";"<<2*node->x<<","<<2*node->y-1<<") ∪ ";
    cout<<"q("<<node->s-1<<";"<<2*node->x<<","<<2*node->y<<")"<<endl;

    for(int i=0;i<4;i++)
        printFormalDyadicForm(node->children[i]);
}
