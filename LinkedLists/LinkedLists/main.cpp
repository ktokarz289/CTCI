using namespace std;
#include <iostream>
#include <string>

struct node
{
	node *next;
	std::string data;
};

node* getTail(node *head);
void createNewNode(node *currNode, string input);
void printNodeData(node *head);

int main()
{
	bool run = true;
	string input;
	node *head = NULL;

	while (run)
	{
		cout << "Please enter a value. Press Q to quit \n";
		cin >> input;
		cout << "\n";

		if (input == "Q" || input == "q")
		{
			run = false;
		}

		if (run)
		{
			if (head == NULL)
			{
				head = new node();
				createNewNode(head, input);
			}
			else
			{
				node *tmpNode = getTail(head);
				createNewNode(tmpNode, input);
			}
		}		
	}

	printNodeData(head);
	system("PAUSE");
}

node* getTail(node *head)
{
	node *tmpNode = head;

	while (tmpNode->next != NULL)
	{
		tmpNode = tmpNode->next;
	}

	return tmpNode;
};

void createNewNode(node *currNode, string input)
{
	currNode->next = new node();
	currNode->next->data = input;
};

void printNodeData(node *head)
{
	node *tmpNode = head;

	if (tmpNode != NULL)
	{
		cout << head->data + "\n";

		while (tmpNode->next != NULL)
		{
			tmpNode = tmpNode->next;
			cout << tmpNode->data + "\n";
		}
	}
};