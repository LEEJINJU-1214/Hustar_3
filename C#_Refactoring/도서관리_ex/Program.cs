using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace BookManageP
{
    delegate bool CompareFuncDele(Book b, string str);
    class Book
    {
        public bool InputData(BookMGR mgr)
        {
            Console.Write("ISBN 입력 : ");
            m_ISBN = Console.ReadLine();
            if (mgr.FindBook(m_ISBN) != null)
            {
                return false;
            }
            ModifyData();
            return true;
        }
        public void ModifyData()
        {
            Console.Write("책제목 입력 : ");
            m_BookName = Console.ReadLine();
            RoofInput(m_Author, "저자");
            RoofInput(m_Contents, "목차");
            Console.Write("출판사 입력 : ");
            m_Publisher = Console.ReadLine();
        }
        public void RoofInput(List<string> List, string str)
        {
            Console.WriteLine("{0} 입력",str);
            string end = "";
            List.Clear();
            while (end != "Enter")
            {
                Console.Write(str+" {0} :", List.Count+1);
                end = Console.ReadLine();
                List.Add(end);
            }
            List.RemoveAt(List.LastIndexOf(List.Last()));
            return;
        }
        public void RoofPrint(List<string> List, string str)
        {
            for(int i=0;i<List.Count;i++)
            {
                Console.WriteLine(str + " {0} :{1}", i+1, List[i]);
            }
        }
        public void PrintData()
        {
            Console.WriteLine("ISBN :{0}", m_ISBN);
            PrintNameANDAuthorData();
            RoofPrint(m_Contents, "목차");
            Console.WriteLine("출판사 :{0}", m_Publisher);
        }
        public void PrintNameANDAuthorData()
        {
            Console.WriteLine("책제목 :{0}", m_BookName);
            RoofPrint(m_Author, "저자");
        }
        public static bool CompareISBN(Book b, string str)
        {
            return b.m_ISBN == str;
        }
        public static bool CompareTitle(Book b, string str)
        {
            return b.m_BookName == str;
        }
        public static bool CompareAuthor(Book b, string str)
        {
            for (int i = 0; i < b.m_Author.Count; i++)
            {
                if (str == b.m_Author[i])
                {
                    return true;
                }
            }
            return false;
        }
        public static bool CompareContent(Book b, string str)
        {
            for (int i = 0; i < b.m_Contents.Count; i++)
            {
                if (b.m_Contents[i].Contains(str))
                {
                    return true;
                }
            }
            return false;
        }
        public static bool CompareFunc(string str, Book b, CompareFuncDele compFunc)
        {
            return compFunc(b, str);
        }   
        private string m_ISBN;
        private string m_BookName;
        private List<string> m_Author = new List<string>();
        private List<string> m_Contents = new List<string>();
        private string m_Publisher;
    }

    class BookMGR
    {
        public void DisplayMenu(int count, string strMenu,string str)
        {
            Console.WriteLine("{0}.{1}(으)로 {2}", count,strMenu,str);
        }
        public void InputBook()
        {
            Book b = new Book();
            if (b.InputData(this) == true)
            {
                m_BookList.Add(b);
                return;
            }
            Console.WriteLine("존재하는 코드입니다");
            return;
        }
        public void PrintBook()
        {
            for (int i = 0; i < m_BookList.Count; i++)
            {
                Book m = (Book)m_BookList[i];
                m.PrintData();
            }
        }
        public ArrayList SearchMultiIndex(string str, CompareFuncDele compFunc)
        {
            ArrayList Result = new ArrayList();
            for (int i = 0; i < m_BookList.Count; i++)
            {
                if (compFunc(m_BookList[i], str))
                {
                    Result.Add(i);
                }
            }
            return Result;     
        }
        public int FindeBookIndex(string str)
        {
            for (int i = 0; i < m_BookList.Count; i++)
            {
                Book m = (Book)m_BookList[i];
                if (Book.CompareISBN(m,str) == true)
                {
                    return i;
                }
            }
            return -1;
        }
        public Book FindBook(string str)
        {
            int index = FindeBookIndex(str);
            if (index != -1)
            {
                return (Book)m_BookList[index];
            }
            return null;
        }
        public void SearchFunc(string strTitle, CompareFuncDele compFunc)
        {
            Console.WriteLine(strTitle);
            string str = Console.ReadLine();
            ArrayList Result = SearchMultiIndex(str,compFunc);
            if(Result.Count !=0)
            {
                for(int i=0;i<Result.Count;i++)
                {
                    m_BookList[(int)Result[i]].PrintData();
                }
                return;
            }
            Console.WriteLine("찾으려는 데이터는 없습니다.");
            return;
        }
        public void SearchBook()
        {
            for(int i=0;i< m_BookMenu.Count;i++)
            {
                DisplayMenu(i + 1, m_BookMenu[i], "검색");
            }
            int iChoice = int.Parse(Console.ReadLine());
            switch (iChoice)
            {
                case 1:
                    SearchFunc("ISBN", Book.CompareISBN);               
                    break;
                case 2:
                    SearchFunc("책제목", Book.CompareTitle);
                    break;
                case 3:
                    SearchFunc("저자", Book.CompareAuthor);
                    break;
                case 4:
                    SearchFunc("목차", Book.CompareContent);
                    break;
                default:
                    break;
            }
        }
        public int PrintSelBookList(ArrayList Result, string str)
        {
            for (int i = 0; i < Result.Count; i++)
            {
                Console.Write("{0}.", i + 1);
                m_BookList[(int)Result[i]].PrintNameANDAuthorData();
            }
            Console.WriteLine("{0}할 책을 선택해주세요", str);
            int iChoice = int.Parse(Console.ReadLine());
            if (iChoice <= Result.Count && iChoice - 1 >= 0)
            {
                return iChoice - 1;
            }
            Console.WriteLine("잘못된 입력입니다");
            return -1;
        }
        public void DeleteFunc(string strTitle, CompareFuncDele compFunc)
        {
            Console.WriteLine(strTitle);
            string str = Console.ReadLine();
            ArrayList Result = SearchMultiIndex(str, compFunc);
            if (Result.Count != 0)
            {
                int index = PrintSelBookList(Result, "삭제");
                if (index != -1)
                {
                    m_BookList.RemoveAt((int)Result[index]);
                    return;
                }
                return;
            }
            Console.WriteLine("삭제하려는 데이터는 없습니다.");
            return;
        }
        public void DeleteBook()
        {
            for (int i = 1; i < m_BookMenu.Count; i++)
            {
                DisplayMenu(i, m_BookMenu[i], "삭제");
            }
            int iChoice = int.Parse(Console.ReadLine());
            switch (iChoice)
            {
                case 1:
                    DeleteFunc("책제목", Book.CompareTitle);
                    break;
                case 2:
                    DeleteFunc("저자", Book.CompareAuthor);
                    break;
                case 3:
                    DeleteFunc("목차", Book.CompareContent);
                    break;
                default:
                    break;
            }
        }
        public void ModifyFunc(string strTitle, CompareFuncDele compFunc)
        {
            Console.WriteLine(strTitle);
            string str = Console.ReadLine();
            ArrayList Result = SearchMultiIndex(str, compFunc);
            if (Result.Count != 0)
            {
                int index = PrintSelBookList(Result, "수정");
                if (index != -1)
                {
                    Book b = (Book)m_BookList[(int)Result[index]];
                    b.ModifyData();
                    return;
                }
                return;
            }
            Console.WriteLine("수정하려는 데이터는 없습니다.");
            return;
        }
        public void ModifyBook()
        {
            for (int i = 1; i < m_BookMenu.Count; i++)
            {
                DisplayMenu(i, m_BookMenu[i], "수정");
            }
            int iChoice = int.Parse(Console.ReadLine());
            switch (iChoice)
            {
                case 1:
                    ModifyFunc("책제목", Book.CompareTitle);
                    break;
                case 2:
                    ModifyFunc("저자", Book.CompareAuthor);
                    break;
                case 3:
                    ModifyFunc("목차", Book.CompareContent);
                    break;
                default:
                    break;
            }
        }
        public void Menu()
        {
            int iChoice = 1;      
            while (iChoice != 0)
            {
                Console.WriteLine("1.도서등록");
                Console.WriteLine("2.도서출력");
                Console.WriteLine("3.도서검색");
                Console.WriteLine("4.도서삭제");
                Console.WriteLine("5.도서수정");
                iChoice = int.Parse(Console.ReadLine());
                switch (iChoice)
                {
                    case 1:
                        InputBook();
                        break;
                    case 2:
                        PrintBook();
                        break;
                    case 3:
                        SearchBook();
                        break;
                    case 4:
                        DeleteBook();
                        break;
                    case 5:
                        ModifyBook();
                        break;
                    default:
                        break;
                }
            }
        }
        private List<Book> m_BookList = new List<Book>();
        private List<string> m_BookMenu = new List<string>() { "ISBN", "책제목", "저자", "목차" };
    }
    class Program
    {
        static void Main(string[] args)
        {
            BookMGR b = new BookMGR();
            b.Menu();
        }
    }
}
