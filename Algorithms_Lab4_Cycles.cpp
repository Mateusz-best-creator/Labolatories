#include<iostream>
#include<vector>
#include <map>
#include <set>
#include <stack>
#include <string>

void dfs(std::map<int, std::vector<int>> graph, int node)
{
    std::set<int> visited;
    std::stack<int> stack;

    visited.insert(node);
    stack.push(node);

    while (!stack.empty())
    {
        int s = stack.top();
        stack.pop();

        for (int i = graph[s].size() - 1; i >= 0; i--)
        {
            int n = graph[s][i];
            if (n == node && visited.size() == graph.size())
            {
                std::cout << "1\n";
                return;
            }
            auto it = visited.find(n);
            if (it == visited.end())
            {
                visited.insert(n);
                stack.push(n);
            }
        }
    }
    std::cout << "0\n";
}

void cycle()
{
    int row_size;
    std::string matrix;
    std::cin >> row_size >> matrix;
    std::map<int, std::vector<int>> graph;
    std::vector<int> temp;

    int counter = 1, local_counter = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        int digit = matrix[i] == '0' ? 0 : 1;
        if (digit == 1)
            temp.push_back(local_counter);
        local_counter++;
        if ((i + 1) % row_size == 0)
        {
            graph[counter++] = temp;
            local_counter = 1;
            temp.clear();
        }
    }
    /*for (auto e : graph)
    {
        std::cout << e.first << ": ";
        for (auto el : e.second)
            std::cout << el << " ";
        std::cout << "\n";
    }
    */
    dfs(graph, 1);
}

int main()
{
    int times;
    std::cin >> times;
    for (int i = 0; i < times; i++)
        cycle();
}