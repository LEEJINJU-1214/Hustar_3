import sys
import os

def cal(x,y): #평균 계산
    return (float(x)*0.5)+(float(y)*0.5)

def grade(x,y):#grade 연산
    result = cal(x,y)
    global list_g
    if result>=90:
        grade=list_g[0]
    elif result>=80:
        grade=list_g[1]
    elif result>=70:
        grade=list_g[2]
    elif result>=60:
        grade=list_g[3]
    else:
        grade=list_g[4]
    return grade

def Command(ls): ##명령어 소문자 전환 후 자동 입출력
    x = input('#')
    x = x.lower()
    com_list = ['show', 'search', 'changescore', 'searchgrade', 'add', 'remove', 'quit']
    if x in com_list:
        if x =='show':
            show(ls)
        elif x=='search':
            search(ls)
        elif x=='changescore':
            changescore(ls)
        elif x=='searchgrade':
            searchgrade(ls)
        elif x=='add':
            add(ls)
        elif x=='remove':
            remove(ls)
        else:
            quit(ls)
    else:
        Command(ls)
        
def sort(ls):#리스트 정렬
    ls_s = sorted(ls,reverse=True, key = lambda x: x[1][-2])
    return ls_s

def print_TN():#테이블네임 출력
    print("%8s %12s %s %s %s %s"%('Student','Name','Midterm','Final','Average','Grade'))
    print('-'*50)   
    
def show(ls):#화면 출력
    ls=sort(ls)#리스트 출력 전 소팅
    print_TN()#테이블네임 출력           
    for key,v in ls:
        a,x,y,z,w = v
        print("%s %12s %5s %6s %7s %4s"%(key,a,x,y,z,w))
    Command(ls)
    
def search(ls):#특정학생 검색
    StudentID = input('Student ID:')
    for key,v in ls:
        if StudentID == key:
            print_TN()
            print("%s %12s %5s %6s %7s %4s"%(StudentID,v[0],v[1],v[2],v[3],v[4]))
            Command(ls)
    print('NO SUCH PERSON.')
    Command(ls)
    
def changescore(ls):
    StudentID = input('Student ID:')
    for key,v in ls:
        if StudentID == key:
            MFConfirm  = input('Mid/Final?')
            MFConfirm = MFConfirm.lower()
            if MFConfirm=='mid':
                Newscore = int(input('Input new score:'))
                if 0<=Newscore<=100:
                    print_TN()
                    print("%s %12s %5s %6s %7s %4s"%(StudentID,v[0],v[1],v[2],v[3],v[4]))
                    v[1] = Newscore
                    v[3] = cal(v[1],v[2])
                    v[4] = grade(v[1],v[2])
                    print("Score changed.")
                    print("%s %12s %5s %6s %7s %4s"%(StudentID,v[0],v[1],v[2],v[3],v[4]))
                    Command(ls)
                else:
                    Command(ls)
            elif MFConfirm=='final':
                Newscore = int(input('Input new score:'))
                if 0<=Newscore<=100:
                    print_TN()
                    print("%s %12s %5s %6s %7s %4s"%(StudentID,v[0],v[1],v[2],v[3],v[4]))
                    v[2] = Newscore
                    v[3] = cal(v[1],v[2])
                    v[4] = grade(v[1],v[2])
                    print("Score changed.")
                    print("%s %12s %5s %6s %7s %4s"%(StudentID,v[0],v[1],v[2],v[3],v[4]))
                    Command(ls)
                else:
                    Command(ls)
            else:
                Command(ls)
    print('NO SUCH PERSON.')
    Command(ls)
    
def add(ls):
    StudentID = input('Student ID:')
    for key,v in ls:
        if StudentID == key:
            print('ALREADY EXISTS.')
            Command(ls)
        else:
            Name = input('Name:')
            # 숫자만 입력가능하게 코딩 필요(0~100사이로)
            MDScore = input('Midterm Score:')
            if 0<=int(MDScore)<=100:
                MDScore  = int(MDScore)
                FNscore = input('Final Score:')
                if 0<=int(FNscore)<=100:
                    FNscore = int(FNscore)
                    ls.append((StudentID,[Name,MDScore,FNscore,cal(MDScore,FNscore),grade(MDScore,FNscore)]))
                    print('Student added.')
                    ls = sort(ls)
                    Command(ls)
                else:
                    print('Score error.')
                    Command(ls)
            else:
                print('Score error')
                Command(ls)
            
def searchgrade(ls):
    grade = input('Grade to search:')
    global list_g
    grade = grade.upper()
    if grade in list_g:
        print_TN()
    else:
        Command(ls)
    count = 0    
    for key,v in ls:
        name,mid,final,avg,grad = v
        if grad==grade:
            count =1
            print("%s %12s %5s %6s %7s %4s"%(key,name,mid,final,avg,grad))
    if count ==0:
        print('NO RESULTS.')
        Command(ls)
    else:
        Command(ls)  
        

def remove(ls):
    if len(ls)==0:
        print('List is empty')
    else:
        StudentID = input('Student ID:')
        for key,v in ls:
            if StudentID == key:
                ls.remove((key,[v[0],v[1],v[2],v[3],v[4]]))
                print('Student removed.')
                Command(ls)
        print('NO SUCH PERSON')
        Command(ls)
    Command(ls)
    #학생이 목록에 없을 경우 
    
def quit(ls):
    save = input('Save data?[yes/no]')
    save = save.lower()
    if (save =='yes') or (save =='no'):
        if save =='yes':
            filename = input('File name:')
            filename = filename.replace(" ","")##공백제거
            with open(filename, 'w') as f:
                for key,v in ls:
                    name,mid,final,avg,grad = map(str,v)
                    f.write("%s %12s %5s %6s %7s %4s\n"%(key,name,mid,final,avg,grad))       
        sys.exit()
    else:
        Command(ls)          
def fileread(file):##파일읽기
    with open(file, 'r') as f:
        for line in f:
            text = line.split()
            list_text.append(text)
        for i in range(len(list_text)):
            d[list_text[i][0]] = [list_text[i][1]+" "+list_text[i][2],list_text[i][-2],list_text[i][-1],cal(list_text[i][-2],list_text[i][-1]),grade(list_text[i][-2],list_text[i][-1])]
        sorted_sl = sorted(d.items(),reverse=True, key = lambda list_text: list_text[1][-2])
    return sorted_sl

if len(sys.argv)==1:
    file = 'students.txt'
else:
    file = sys.argv[1]
    
d ={}
list_g = ['A','B','C','D','F']
list_text = []
if os.path.exists(file):
        show(fileread(file))

else:
    file = 'students.txt'
    show(fileread(file))
