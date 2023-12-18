using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace saod5
{
    public class Node<T>
    {
            public T Value;
            public Node<T> Next;

            public Node(T value)
            {
                Value = value;
                Next = null;
            }
        
    }
}
