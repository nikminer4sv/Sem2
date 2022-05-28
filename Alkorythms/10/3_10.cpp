#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Temp(bool** mas, vector<int> temp_nodes, vector<vector<int>>& nodes, int node, int& size, int maxNode = 4); // maxNode -> last node has a way

int main()
{
    system("cls");
    int size;
    cout << "amount of nodes: ";
    cin >> size;

    bool** mas = new bool* [size] {};
    for (size_t i = 0; i < size; i++)
    {
        mas[i] = new bool[size] {0};
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << i + 1 << " -> " << j + 1 << " ? (0 or 1) : ";
            bool temp;
            cin >> temp;
            if (temp)
            {
                mas[i][j] = 1;
            }
        }
        
    }
    vector<vector<int>> nodes{};

    size_t i = 0; // first node has a way

    vector<int> temp_nodes{};
    for (size_t j = 0; j < size; j++)
    {
        if (mas[i][j] == 1)
        {
            temp_nodes.push_back(i);
            temp_nodes.push_back(j);
            Temp(mas, temp_nodes, nodes, j, size);
        }
        temp_nodes.clear();
    }

    for (auto tempNode : nodes)
    {
        size = tempNode.size();
        cout << "D = " << size << endl;
        for (int temp : tempNode)
        {
            cout << temp + 1;
            if (size > 1)
            {
                cout << " -> ";
                size--;
            }
        }
        cout << endl;
    }

    bool isSameWay = false;

    for (size_t j = 0; j < nodes.at(i).size(); j++)
    {
        if (nodes[0][0] == nodes[j][0] && nodes[0][nodes[0].size() - 1] == nodes[j][nodes[j].size() - 1])
        {
            isSameWay = true;
            break;
        }
        else
            isSameWay = false;
    }

    vector<int> NodeF{};
    if (isSameWay)
    {
        cout << "check" << endl;

        for (size_t i = 0, rows = nodes.size() - 1; rows >= nodes.size() / 2; i++, rows--)
        {
            for (size_t j = 1; j < nodes[rows].size(); j++)
            {
                auto it = find(nodes[i].begin(), nodes[i].end(), nodes[rows][j]);
                if (it == nodes[i].end())
                    continue;
                if (*it != nodes[i][nodes[i].size() - 1])
                    NodeF.push_back(nodes[rows][j]);
            }
        }
    }

    for (int temp : NodeF)
        cout << temp + 1 << " ";
    cout << endl;

    return 0;
}

void Temp(bool** mas, vector<int> temp_nodes, vector<vector<int>>& nodes, int node, int& size, const int maxNode)
{
    for (size_t j = 0; j < size; j++)
    {
        if ((mas[node][j] == 1) && (find(temp_nodes.begin(), temp_nodes.end(), j) == temp_nodes.end()))
        {
            temp_nodes.push_back(j);

            if (j == maxNode)
            {
                nodes.push_back(temp_nodes);
                return;
            }

            Temp(mas, temp_nodes, nodes, j, size);
            temp_nodes.pop_back();
        }
    }
}