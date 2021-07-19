using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace MemberTest
{

    class Member
    {
        public bool InputData(MemberMgr mgr)
        {
            Console.Write("이름 : ");
            m_MemName = Console.ReadLine();
            if (mgr.FindeMember(m_MemName) != null)
            {
                return false;
            }
            ModifyData();
            return true;

        }
        public void PrintData()
        {
            Console.WriteLine("이름 : {0}", m_MemName);
            Console.WriteLine("주소 : {0}", m_MemAddr);
            Console.WriteLine("전화번 : {0}", m_MemTelNo);
        }
        public bool CompareData(string SearchName)
        {
            return SearchName == m_MemName;
        }
        public void ModifyData()
        {
            Console.Write("주소 : ");
            m_MemAddr = Console.ReadLine();
            Console.Write("전화번호 : ");
            m_MemTelNo = Console.ReadLine();
        }
        public bool ContainName(string SearchName)
        {
            return m_MemName.Contains(SearchName);
        }
        private string m_MemName;
        private string m_MemAddr;
        private string m_MemTelNo;

    }
    class MemberMgr
    {
        public void InputMember()
        {
            Member m = new Member();
            if (m.InputData(this) == true)
            {
                MemList.Add(m);
            }
            else
            {
                Console.WriteLine("존재하는 사람입니다");
            }
        }
        public int FindeMemberIndex(string SearchName)
        {
            for (int i = 0; i < MemList.Count; i++)
            {
                Member m = (Member)MemList[i];
                if (m.CompareData(SearchName) == true)
                {
                    return i;
                }
            }
            return -1;
        }
        public Member FindeMember(string SearchName)
        {
            int index = FindeMemberIndex(SearchName);
            if (index != -1)
            {
                return (Member)MemList[index];
            }
            return null;
        }
        public void PrintMember()
        {
            for (int i = 0; i < MemList.Count; i++)
            {
                Member m = (Member)MemList[i];
                m.PrintData();
            }


        }
        public void SearchMember()
        {
            Console.Write("찾을려는 이름을 입력해주세요 : ");
            string Searchname = Console.ReadLine();
            Member m = FindeMember(Searchname);
            if (m != null)
            {
                m.PrintData();
            }
            else
            {
                Console.WriteLine("해당 회원은 존재하지 않습니다");
            }
        }
        public void ModifyMember()
        {
            Console.Write("수정하려는 이름을 입력해주세요 : ");
            string Modifyname = Console.ReadLine();
            Member m = FindeMember(Modifyname);
            if (m != null)
            {
                m.ModifyData();
            }
            else
            {
                Console.WriteLine("해당 회원은 존재하지 않습니다");
            }
        }

        public void DeleteMember()
        {
            Console.Write("삭제하려는 이름을 입력해주세요 : ");
            string Deletename = Console.ReadLine();
            int index = FindeMemberIndex(Deletename);
            if (index != -1)
            {
                MemList.RemoveAt(index);
            }
            else
            {
                Console.WriteLine("해당 회원은 존재하지 않습니다");
            }
        }
        public ArrayList FindeMemberMulitIndex(string Searchname)
        {
            ArrayList Result = new ArrayList();

            for (int i = 0; i < MemList.Count; i++)
            {
                Member m = (Member)MemList[i];
                if (m.ContainName(Searchname) == true)
                {
                    Result.Add(i);
                }
            }
            return Result;
        }
        public void PrintMember(ArrayList IndexList)
        {
            for (int i = 0; i < IndexList.Count; i++)
            {
                Member m = (Member)MemList[(int)IndexList[i]];
                m.PrintData();
            }
        }
        public void MultiSearchMember()
        {
            Console.Write("찾을려는 문자열을 입력해주세요 : ");
            string Searchname = Console.ReadLine();
            ArrayList IndexList = FindeMemberMulitIndex(Searchname);
            if (IndexList.Count > 0)
            {
                PrintMember(IndexList);
            }
            else
            {
                Console.WriteLine("해당 회원은 존재하지 않습니다");
            }
        }
        public void DeletMember(ArrayList IndexList)
        {

            for (int i = IndexList.Count - 1; i >= 0; i--)
            {
                MemList.RemoveAt((int)IndexList[i]);
            }
        }
        public void MultiDeleteMember()
        {
            Console.Write("삭제하려는 문자열을 입력해주세요 : ");
            string Deletename = Console.ReadLine();
            ArrayList IndexList = FindeMemberMulitIndex(Deletename);
            if (IndexList.Count > 0)
            {
                DeletMember(IndexList);
            }
            else
            {
                Console.WriteLine("해당 회원은 존재하지 않습니다");
            }
        }
        public void menu()
        {
            int iChoice = 1;
            while (iChoice != 0)
            {
                Console.WriteLine("1.회원등록");
                Console.WriteLine("2.회원출력");
                Console.WriteLine("3.회원검색");
                Console.WriteLine("4.회원수정");
                Console.WriteLine("5.회원삭제");
                Console.WriteLine("6.다중검색");
                Console.WriteLine("7.다중삭제");
                iChoice = int.Parse(Console.ReadLine());
                switch (iChoice)
                {
                    case 0:

                        break;
                    case 1:
                        InputMember();
                        break;
                    case 2:
                        PrintMember();
                        break;
                    case 3:
                        SearchMember();
                        break;
                    case 4:
                        ModifyMember();
                        break;
                    case 5:
                        DeleteMember();
                        break;
                    case 6:
                        MultiSearchMember();
                        break;
                    case 7:
                        MultiDeleteMember();
                        break;
                    default:
                        break;

                }
            }
        }
        private ArrayList MemList = new ArrayList();
    }
    class Program
    {
        static void Main(string[] args)
        {
            MemberMgr m = new MemberMgr();
            m.menu();
        }
    }
}
