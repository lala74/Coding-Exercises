#pragma once

template <class Entry>
class Node
{
public:
    Node();
    Node(Entry data, Node<Entry>* pNodeToLink = nullptr);
    ~Node();
    
    Entry m_data;
    Node<Entry>* m_next;
};

/********************************* */
// Constuctor
template <class Entry>
Node<Entry>::Node() : m_next(nullptr)
{
}

template <class Entry>
Node<Entry>::Node(Entry data, Node<Entry>* pNodeToLink)
{
    m_data = data;
    m_next = pNodeToLink;
}

template <class Entry>
Node<Entry>::~Node()
{
}