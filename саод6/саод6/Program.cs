using System.ComponentModel;
using System.Data;

namespace Binary_Search_Tree_lesson_6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DateTime currentTime = DateTime.Now;
            BinarySearchTree<int> tree = new BinarySearchTree<int>();
            for (int i = 0; i < 10; i++)
            {
                int valuie = (int.Parse(i.ToString() + i.GetHashCode().ToString()) 
                    * currentTime.Ticks.GetHashCode() / 1466) % 100 ;
                tree.Insert(valuie);
            }
            tree.Insert(5);
            tree.InOrderTraversal();

            int searchValue = 5;
            bool found = tree.Search(searchValue);

            if (found)
            {
                Console.WriteLine($"\n Найдено значение {searchValue}");
            }
            else
            {
                Console.WriteLine($"\n Не найденозначение {searchValue}");
            }
            int leafCount = tree.LeafCount();
            Console.WriteLine($"\n Количество листьев в дереве: {leafCount}");
        }
    }
}