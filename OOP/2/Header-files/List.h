#pragma once

#include <iostream>

template <class T>
class List
{
public:
	struct Node
	{
		T value{};
		Node *next = nullptr;

		Node() {}

		Node(const T &val, Node *next = nullptr)
			: value(val), next(next) {}
	};

public:
	List() {}

	List(const List &list)
	{
		this->size = list.GetSize();

		Node *node = list.head;
		while (node != nullptr)
		{
			Append(node->value);
			node = node->next;
		}
	}

	/*~List() {
		Clear();
	}
	void Clear() {
		Node* temp = head;
		while (temp->next != nullptr) {
			Node* gg = temp;
			temp = temp->next;
			delete gg;
		}
		this->head = nullptr;
		this->size = 0;
	}*/

	int GetSize() const
	{
		return this->size;
	}

	void Append(T element)
	{

		this->size += 1;
		Node *newNode = new Node;
		newNode->value = element;

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node *node = head;
		while (node->next != nullptr)
			node = node->next;

		node->next = newNode;
	}

	void Remove(const size_t &index)
	{
		if (index < 0 || index > size - 1)
			throw std::invalid_argument("index is out of bounds");

		if (index == 0)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node *temp = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}

		Node *toremove = temp->next;
		temp->next = temp->next->next;
		delete toremove;

		this->size -= 1;
	}

	T &operator[](size_t index)
	{

		if (index < 0 || index > size - 1)
			throw std::invalid_argument("index is out of bounds");

		Node *temp = head;
		for (size_t i = 0; i < index; i++)
			temp = temp->next;

		return temp->value;
	}

	T operator[](size_t index) const
	{

		if (index < 0 || index > size - 1)
			throw std::invalid_argument("index is out of bounds");

		Node *temp = head;
		for (size_t i = 0; i < index; i++)
			temp = temp->next;

		return temp->value;
	}

	List<T> &operator=(const List<T> &list)
	{

		this->size = list.size;

		this->Clear();
		for (size_t i = 0; i < this->size; i++)
			this->Append(list[i]);

		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const List<T> &list)
	{

		if (list.GetSize() == 0)
			return os;

		Node *node = list.head;
		while (node->next != nullptr)
		{
			os << node->value << " ";
			node = node->next;
		}

		os << node->value;

		return os;
	}

private:
	size_t size = 0;
	Node *head = nullptr;
};