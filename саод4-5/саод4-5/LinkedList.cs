using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace saod5
{
    public class CircularLinkedList<T>
    {
        private Node<T> _last;

        public void PushBack(T value)
        {
            var newNode = new Node<T>(value);
            if (_last == null)
            {
                _last = newNode;
                _last.Next = _last;
            }
            else
            {
                newNode.Next = _last.Next;
                _last.Next = newNode;
                _last = newNode;
            }
        }

        public void PushFront(T value)
        {
            var newNode = new Node<T>(value);
            if (_last == null)
            {
                _last = newNode;
                _last.Next = _last;
            }
            else
            {
                newNode.Next = _last.Next;
                _last.Next = newNode;
            }
        }

        public void Insert(int index, T value)
        {
            if (index < 0 || index > Count)
            {
                throw new IndexOutOfRangeException("Index is out of range");
            }
            if (index == 0)
            {
                PushFront(value);
            }
            else if (index == Count)
            {
                PushBack(value);
            }
            else
            {
                var newNode = new Node<T>(value);
                var current = _last.Next;
                for (int i = 1; i < index; i++)
                {
                    current = current.Next;
                }
                newNode.Next = current.Next;
                current.Next = newNode;
            }
        }

        public void PopBack()
        {
            if (_last == null)
            {
                throw new InvalidOperationException("List is empty");
            }
            if (_last.Next == _last)
            {
                _last = null;
            }
            else
            {
                var current = _last.Next;
                while (current.Next != _last)
                {
                    current = current.Next;
                }
                current.Next = _last.Next;
                _last = current;
            }
        }

        public void PopFront()
        {
            if (_last == null)
            {
                throw new InvalidOperationException("List is empty");
            }
            if (_last.Next == _last)
            {
                _last = null;
            }
            else
            {
                _last.Next = _last.Next.Next;
            }
        }

        public void RemoveAt(int index)
        {
            if (index < 0 || index >= Count)
            {
                throw new IndexOutOfRangeException("Index is out of range");
            }
            if (index == 0)
            {
                PopFront();
            }
            else
            {
                var current = _last.Next;
                for (int i = 1; i < index; i++)
                {
                    current = current.Next;
                }
                current.Next = current.Next.Next;
            }
        }

        public T this[int index]
        {
            get
            {
                var current = _last.Next;
                for (int i = 0; i < index; i++)
                {
                    current = current.Next;
                }
                return current.Value;
            }
            set
            {
                var current = _last.Next;
                for (int i = 0; i < index; i++)
                {
                    current = current.Next;
                }
                current.Value = value;
            }
        }

        public int Count
        {
            get
            {
                if (_last == null)
                {
                    return 0;
                }
                var count = 1;
                var current = _last.Next;
                while (current != _last)
                {
                    count++;
                    current = current.Next;
                }
                return count;
            }
        }

        public bool Empty()
        {
            return _last == null;
        }

        public void Clear()
        {
            _last = null;
        }

        public T First()
        {
            if (_last == null)
            {
                throw new InvalidOperationException("List is empty");
            }
            return _last.Next.Value;
        }

        public T Last()
        {
            if (_last == null)
            {
                throw new InvalidOperationException("List is empty");
            }
            return _last.Value;
        }
    }
}
