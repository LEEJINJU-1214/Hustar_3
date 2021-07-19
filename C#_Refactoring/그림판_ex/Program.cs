using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0511_2
{
    interface iDrawObject
    {
        void Draw();
        string GetDrawObjectName();
        iDrawObject Clone();//본인을 복사하여 리턴하는 함수

    }
    class Line : iDrawObject
    {
        public iDrawObject Clone()
        {
            return new Line();
        }
       public void Draw()
        {
            Console.WriteLine("라인 그리기");
        }

        public string GetDrawObjectName()
        {
            return "라인";
        }
    }
    class Triangle : iDrawObject
    {
        public iDrawObject Clone()
        {
            return new Triangle();
        }
        public void Draw()
        {
            Console.WriteLine("삼각형 그리기");
        }

        public string GetDrawObjectName()
        {
            return "삼각형";
        }
    }
    class Rectangle : iDrawObject
    {
        public iDrawObject Clone()
        {
            return new Rectangle();
        }
        public void Draw()
        {
            Console.WriteLine("사각형 그리기");
        }

        public string GetDrawObjectName()
        {
            return "사각형";
        }
    }
    class Circle : iDrawObject
    {
        public iDrawObject Clone()
        {
            return new Circle();
        }
        public void Draw()
        {
            Console.WriteLine("원형 그리기");
        }

        public string GetDrawObjectName()
        {
            return "원형";
        }
    }
    class FreeLine : iDrawObject
    {
        public iDrawObject Clone()
        {
            return new FreeLine();
        }
        public void Draw()
        {
            Console.WriteLine("라인 그리기 시작");
            for(int i = 0;i<m_FreeLine.Count;i++)
            {
                m_FreeLine[i].Draw();
            }
            Console.WriteLine("자유곡선 그리기 종료");
        }

        public string GetDrawObjectName()
        {
            return "자유곡선";
        }

        private List<iDrawObject> m_FreeLine = new List<iDrawObject>() { new Line(), new Line(), new Line(), new Line(), new Line(), new Line(), new Line() };
    }
    class ToolbarMenu
    {
        private List<iDrawObject> m_MenuObject = new List<iDrawObject>()
        {
            new Line(),new Triangle(), new Rectangle(), new Circle(), new FreeLine()
        };
        private List<iDrawObject> m_MenuBuffer = new List<iDrawObject>();

        public int PrintToolbarMenu(List<iDrawObject> m_Menu)
        {
            int i = 0;
            for (; i < m_Menu.Count; i++)
            {
                Console.WriteLine("{0}.{1}", i + 1, m_Menu[i].GetDrawObjectName());
            }
            return i;
        }

        public void MenuManage(List<iDrawObject> m_MenuObject, List<iDrawObject> m_MenuBuffer, int index)
        {

            int insertMenu = 1;

            if (index != 0)//추가일경우
            {
                Console.WriteLine("추가 메뉴 선택");
                insertMenu = int.Parse(Console.ReadLine());

            }
          
            m_MenuObject.Insert(0, m_MenuBuffer[insertMenu - 1]);
            m_MenuBuffer.RemoveAt(insertMenu - 1);

        }

        public iDrawObject SelectDrawObject()
        {
            int index = PrintToolbarMenu(m_MenuObject);
            Console.WriteLine("{0}.메뉴삭제", index + 1);//메뉴가 동적으로 변하며 사라짐.-> 메뉴를 배열에 넣었기에 가능!!
            Console.WriteLine("{0}.메뉴추가", index + 2);// 현재 버퍼에 저장된 메뉴가 뜨고 번호를 누르며 걔가 복원되는 거 코딩

            int iObjectGubun = int.Parse(Console.ReadLine());


            if (iObjectGubun == index + 1)//삭제일경우
            {
                MenuManage(m_MenuBuffer, m_MenuObject,  0);
            }
            else if (m_MenuBuffer.Count > 0 && iObjectGubun == index + 2)//추가일경우
            {
                int insertindex = PrintToolbarMenu(m_MenuBuffer);
                MenuManage(m_MenuObject, m_MenuBuffer, insertindex);
            }        
            if(iObjectGubun<=0||iObjectGubun>=m_MenuObject.Count)
            {
                return null;
            }
            return m_MenuObject[iObjectGubun - 1];
        }
    }
    class PaintShop
    {
        public void DrawPaintShop()
        {
            for (int i = 0; i < m_DrawList.Count; i++)
            {
                m_DrawList[i].Draw();
            }
        }
        public void InputDrawObject(iDrawObject selObject)
        {
            if (selObject != null)
            {
                m_DrawList.Add(selObject.Clone());
            }
        }
        public void Menu()
        {
            int iChoice = 1;
            iDrawObject selObject = null;

            while (iChoice != 0)
            {
                Console.WriteLine("1.객체선택");
                Console.WriteLine("2.그리기");
                Console.WriteLine("3.그림판보기");
                iChoice = int.Parse(Console.ReadLine());
                switch (iChoice)
                {
                    case 1:
                        {
                            selObject = m_ToolBarMenu.SelectDrawObject();
                        }
                        break;
                    case 2:
                        {
                            InputDrawObject(selObject);
                        }
                        break;
                    case 3:
                        {
                            DrawPaintShop();
                        }
                        break;
                    default:
                        break;
                }

            }
        
    }
        //포함관계
        List<iDrawObject> m_DrawList = new List<iDrawObject>();//클래스는 변수가 기준
        ToolbarMenu m_ToolBarMenu = new ToolbarMenu();//메뉴에서만 사용되는 것//그림판의 구성품으로 생각시 밑에 둠.
    }
    class Program
    {
        static void Main(string[] args)
        {
            PaintShop p = new PaintShop();
            p.Menu();
        }
    }
}
