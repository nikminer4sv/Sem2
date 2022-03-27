#pragma once

#include <iostream>

template <typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T value{};
		Node *next = nullptr;
		Node *prev = nullptr;

		Node(const T &val, Node *prev = nullptr, Node *next = nullptr)
			: value(val), prev(prev), next(next) {}
	};

public:
	DoublyLinkedList() = default;

	DoublyLinkedList(const DoublyLinkedList &list)
	{
		copy(list);
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear()
	{
		Node *current = head;
		while (current)
		{
			Node *temp = current;
			current = current->next;
			delete temp;
		}

		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	int GetSize() const
	{
		return this->size;
	}

	void Append(const T &element)
	{
		size += 1;

		if (head == nullptr)
		{
			head = tail = new Node(element);
			return;
		}

		tail->next = new Node(element, tail);
		tail = tail->next;
	}

	void Remove(const size_t &index)
	{
		if (index > size - 1)
			throw std::invalid_argument("index is out of bounds");

		size -= 1;

		if (index == 0)
		{
			auto *temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node *to_remove = head;
		for (int i = 0; i < index; i++)
			to_remove = to_remove->next;

		to_remove->prev->next = to_remove->next;
		to_remove->next->prev = to_remove->prev;
		delete to_remove;
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

	const T &operator[](size_t index) const
	{

		if (index < 0 || index > size - 1)
			throw std::invalid_argument("index is out of bounds");

		Node *temp = head;
		for (size_t i = 0; i < index; i++)
			temp = temp->next;

		return temp->value;
	}

	T &operator=(const DoublyLinkedList<T> &list)
	{
		Clear();
		copy(list);
	}

	friend std::ostream &operator<<(std::ostream &os, const List<T> &list)
	{
		Node *node = list.head;
		while (node != nullptr)
		{
			os << node->value << " ";
			node = node->next;
		}

		return os;
	}

private:
	void copy(const DoublyLinkedList<T> &list)
	{
		this->size = list.GetSize();

		Node *node = list.head;
		while (node != nullptr)
		{
			append(node->value);
			node = node->next;
		}
	}

	size_t size = 0;
	Node *head = nullptr;
	Node *tail = nullptr;
};