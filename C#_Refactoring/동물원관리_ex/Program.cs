using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace _0512_zoo_ex
{
    abstract class animal
    {
        public abstract void speak();
        public abstract animal Clone(int index);
        public abstract string GetShapeName();
        public abstract string GetName();
        public int GetCount(int index)
        {
            return Count[index];
        }
        public void DeleteCount(int index)
        {
            Count[index] -= 1;
        }
        public void ADDCount(int index)
        {
            Count[index] += 1;
        }
        public string Getzoo()
        {
            return m_zoo;
        }
        public  void RocateZoo(string Zoo)
        {
            m_zoo = Zoo;
            Console.WriteLine("{0} {1}로 이동", this.GetName(), m_zoo);
        }
        public void InputData()
        {
            Console.Write("{0}이름 : ", this.GetShapeName());
            m_Name = Console.ReadLine();
            Console.Write("{0}나이 : ", this.GetShapeName());
            m_AGE = Console.ReadLine();
            
        }
        public int COUNT//Count 리셋용
        {
            set
            {               
                Count.Add(value);
                Count[value] = 0;
            }
        }
        protected string m_Name;
        protected string m_AGE;
        protected string m_zoo;
        protected static List<int> Count = new List<int>();
    }
    class Dog : animal
    {
        public override animal Clone(int index)
        {
            animal m = new Dog();
            Count[index] += 1;
            m.InputData();
            return m;
        }     
        public override void speak()
        {
            Console.WriteLine("멍멍");
        }
        public override string GetShapeName()
        {
            return "개";
        }
        public override string GetName()
        {
            return m_Name;
        }     
    }
    class Cat : animal
    {
        public override animal Clone(int index)
        {
            animal m = new Cat();
            Count[index] += 1;
            m.InputData();
            return m;
        }
        public override void speak()
        {
            Console.WriteLine("야옹");
        }
        public override string GetShapeName()
        {
            return "고양이";
        }
        public override string GetName()
        {

            return m_Name;
        }
      
    }
    class Lion : animal
    {
        public override animal Clone(int index)
        {
            animal m = new Lion();
            Count[index] += 1;
            m.InputData();
            return m;
        }
        public override void speak()
        {
            Console.WriteLine("어흥");
        }

        public override string GetShapeName()
        {
            return "사자";
        }
        public override string GetName()
        {
            return m_Name;
        }
       
    }
    class Tiger : animal
    {
        public override animal Clone(int index)
        {
            animal m = new Tiger();
            Count[index] += 1;
            m.InputData();
            return m;
        }
      
        public override void speak()
        {
            Console.WriteLine("어흥:타이거");

        }

        public override string GetShapeName()
        {
            return "타이거";
        }
        public override string GetName()
        {

            return m_Name;
        }
        
    }
    class Horce : animal
    {
        public override animal Clone(int index)
        {
            animal m = new Horce();
            Count[index] += 1;
            m.InputData();
            return m;
        }
        
    
        public override void speak()
        {
            Console.WriteLine("이히힝");
        }
        public override string GetShapeName()
        {
            return "말";
        }
        public override string GetName()
        {

            return m_Name;
        }
       
    }

    class AnimalManage
    {
   
        public void InputAnimal(int SelAnimal)
        {
            Console.WriteLine("번호를 입력해주세요");
            SelAnimal = int.Parse(Console.ReadLine());

            if (0 < SelAnimal || SelAnimal < 8)
            {
                Total_AnimalList.Add(Total_AnimalListMenu[SelAnimal-1].Clone(SelAnimal - 1));//새객체를 만들지 않으면 이름 등의 값이 다 바뀜
                return;
            }
            Console.WriteLine("잘못된 입력입니다");
        }

        public void DeleteAnimal()
        {
            PrintAnimalName(Total_AnimalList);
            string SelAnimal = Console.ReadLine();
            if (SearchanimalIndex(SelAnimal, Total_AnimalList) != -1)
            {
                int MenuListindex = Total_AnimalListMenu.IndexOf(Total_AnimalListMenu[SearchanimalIndex(SelAnimal, Total_AnimalList)]);
                Total_AnimalList[SearchanimalIndex(SelAnimal, Total_AnimalList)].DeleteCount(MenuListindex);
                Total_AnimalList.RemoveAt(SearchanimalIndex(SelAnimal, Total_AnimalList));
            }
            else
            {
                Console.WriteLine("잘못된 입력입니다");
            }
        }
        public void SpeakAnimal()
        {
            for (int i = 0; i < Total_AnimalList.Count; i++)
            {
                Total_AnimalList[i].speak();
              
            }         
        }
        public void StatisticAnimal()
        {
            for (int i = 0; i < Total_AnimalListMenu.Count; i++)
            {
                if (Total_AnimalListMenu[i].GetCount(i) != 0)
                {
                    Console.WriteLine("{0} {1}마리", Total_AnimalListMenu[i].GetShapeName(), Total_AnimalListMenu[i].GetCount(i));
                }
            }
        }
   
        public void PrintAnimalList(List<animal> Total_AnimalList)
        {        
            for (int i = 0; i < Total_AnimalList.Count; i++)
            {
                Console.WriteLine("{0}. {1}", i + 1, Total_AnimalList[i].GetShapeName());
            }
            
        }
        public void PrintAnimalName(List<animal> Total_AnimalList)
        {
            for (int i = 0; i < Total_AnimalList.Count; i++)
            {
                Console.WriteLine("{0}.{1}", i + 1, Total_AnimalList[i].GetName());
            }
        }
 
        public int SearchanimalIndex(string SelAnimal, List<animal> Total_AnimalList)
        {
            for (int i = 0; i < Total_AnimalList.Count; i++)
            {
                if (Total_AnimalList[i].GetName().Equals(SelAnimal))
                {
                    return i;
                }
            }
            return -1;
        }
        public int SearchanimalshapeIndex(animal AftZoo_AnimalList, List <animal> Total_AnimalList)
        {
            for (int i = 0; i < Total_AnimalList.Count; i++)
            {
                if (Total_AnimalList[i].GetShapeName().Equals(AftZoo_AnimalList.GetShapeName()))
                {
                    return i;
                }
            }
            return -1;
        }
        public void Rocate(List<animal> PreZoo_AnimalList, List<animal> AftZoo_AnimalList)
        {
            if (PreZoo_AnimalList.Count != 0)
            {
                PrintAnimalName(PreZoo_AnimalList);
                Console.WriteLine("동물이름을 입력해주세요");
                string SelAnimal = Console.ReadLine();
                if (SearchanimalIndex(SelAnimal, PreZoo_AnimalList) != -1)
                {
                    int Locateindex = SearchanimalIndex(SelAnimal, PreZoo_AnimalList);
                    AftZoo_AnimalList.Add(PreZoo_AnimalList[Locateindex]);       
                    int MenuListindex = SearchanimalshapeIndex(AftZoo_AnimalList.Last(), Total_AnimalListMenu);

                    if(PreZoo_AnimalList==Total_AnimalList)//A->B
                    {
                        PreZoo_AnimalList[SearchanimalIndex(SelAnimal, PreZoo_AnimalList)].DeleteCount(MenuListindex);
                    }
                    else//B->A
                    {
                        AftZoo_AnimalList.Last().ADDCount(MenuListindex);
                    }
                    PreZoo_AnimalList.RemoveAt(SearchanimalIndex(SelAnimal, PreZoo_AnimalList));
                    return;
                }
                else
                {
                    Console.WriteLine("잘못된 입력입니다");
                    return;
                }
            }
            Console.WriteLine("동물이 존재하지 않습니다");
            return;
        }

        public void ResetCount(List<animal> Total_AnimalListMenu)//Count리스트 초기화
        {
            for (int i = 0; i < Total_AnimalListMenu.Count; i++)
            {
                Total_AnimalListMenu[i].COUNT = i;
            }
        }
        public void Menu()
        {
            int iChoice = 1;
            ResetCount(Total_AnimalListMenu);
            while (iChoice != 0)
            {
                int SelAnimal = 0;
                
                Console.WriteLine("1.동물추가");
                Console.WriteLine("2.동물삭제");//a동물원만
                Console.WriteLine("3.Speak");//a동물원만
                Console.WriteLine("4.동물통계");//a동물원만
                Console.WriteLine("5.동물이송(A->B)");
                Console.WriteLine("6.동물이송(B->A)");
                
                iChoice = int.Parse(Console.ReadLine());
                switch (iChoice)
                {
                    case 1:
                        PrintAnimalList(Total_AnimalListMenu);           
                        InputAnimal(SelAnimal);                   
                        break;
                    case 2:
                        DeleteAnimal();                    
                        break;
                    case 3:
                        SpeakAnimal();
                        break;
                    case 4:
                        StatisticAnimal();
                        break;
                    case 5:
                        Rocate(Total_AnimalList, Total_ZooBAnimalList);
                        break;
                    case 6:
                        Rocate(Total_ZooBAnimalList, Total_AnimalList);
                        break;
                    default:
                        break;
                }
            }
        }
        private static List<animal> Total_AnimalListMenu = new List<animal>() { new Dog(), new Cat(), new Lion(), new Tiger(), new Horce() };
        private static List<animal> Total_AnimalList = new List<animal>() { };
        private static List<animal> Total_ZooBAnimalList = new List<animal>() { };

    }
    class Program
    {
        static void Main(string[] args)
        {
            AnimalManage a = new AnimalManage();
            a.Menu();
        }
    }
}

