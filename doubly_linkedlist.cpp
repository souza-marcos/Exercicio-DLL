template <typename T>
struct NodeDLL
{
    T data;
    NodeDLL<T> *next = NULL;
    NodeDLL<T> *prev = NULL;
};

template <typename T>
struct DoublyLinkedList
{
    NodeDLL<T> *head = NULL;
    NodeDLL<T> *last = NULL;
};

template <typename T>
DoublyLinkedList<T> *create()
{
    DoublyLinkedList<T> *list = new DoublyLinkedList<T>;
    return list;
}

template <typename T>
bool isEmpty(DoublyLinkedList<T> *list)
{
    return (list->head == NULL);
}

template <typename T>
void insertBack(T data, DoublyLinkedList<T> *list)
{
    if (isEmpty(list))
    {
        list->head = new NodeDLL<T>;
        list->last = list->head;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->head->data = data;
        return;
    }
    list->last->next = new NodeDLL<T>;
    list->last->next->prev = list->last;
    list->last = list->last->next;
    list->last->data = data;
}

template <typename T>
void insertFront(T data, DoublyLinkedList<T> *list)
{
    if (isEmpty(list))
    {
        list->head = new NodeDLL<T>;
        list->last = list->head;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->head->data = data;
        return;
    }
    list->head->prev = new NodeDLL<T>;
    list->head->prev->next = list->head;
    list->head = list->head->prev;
    list->head->data = data;
}

template <typename T>
void printList(DoublyLinkedList<T> *list, void (*print)(T))
{
    NodeDLL<T> *current = list->head;
    while (current != NULL)
    {
        print(current->data);
        current = current->next;
    }
}

template <typename T, typename Q>
NodeDLL<T> *searchItem(DoublyLinkedList<T> *list, Q val, bool (*compare)(T, Q))
{
    if (isEmpty(list))
    {
        return NULL;
    }
    NodeDLL<T> *current = list->head;

    do
    {
        if (compare(current->data, val))
        {
            return current;
        }
        current = current->next;
    } while (current != NULL);
    return NULL;
}

template <typename T>
void insertAftElem(T data, DoublyLinkedList<T> *list, NodeDLL<T> *elem)
{
    if (isEmpty(list))
    {
        return;
    }

    NodeDLL<T> *aux = new NodeDLL<T>;
    aux->data = data;
    aux->next = elem->next;
    aux->prev = elem;
    elem->next = aux;

    if (elem->next != NULL)
    {
        aux->next->prev = aux;
    }
    else
    {
        list->last = aux;
    }
}

template <typename T>
bool deleteItem(DoublyLinkedList<T> *list, NodeDLL<T> *&node)
{
    if (node == NULL)
    {
        return false;
    }

    if (node != list->head && node != list->last)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    if (node == list->head)
    {
        list->head = node->next;
        if (list->head != NULL)
        {
            list->head->prev = NULL;
        }
    }
    if (node == list->last)
    {
        list->last = node->prev;
        if (list->last != NULL)
        {
            list->last->next = NULL;
        }
    }
    delete node;
    return true;
}