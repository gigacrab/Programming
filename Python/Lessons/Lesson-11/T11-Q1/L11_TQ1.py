#T11-Q1

found=False

search=input('enter a student name to search for :') 
gradeList=open('markList.txt','r')

name=gradeList.readline()#read the first data
#print(name)
while name!='':#repeat until a blank line is found(EOF)
         test1=float(gradeList.readline())
         test2=float(gradeList.readline())
         test3=float(gradeList.readline())
         name=name.rstrip('\n') #to ensure no leading whitespaces at the end of string
         if name.title()==search.title():
             print('test 1:',test1)
             print('test 2:',test2)
             print('test 3:',test3)
             average=(test1+test2+test3)/3
             if average >=90:
                 print('Congrats!',name.title(),'test marks average:',format(average,'.2f'))
             found=True 
         name=gradeList.readline()

gradeList.close()

if not found:
    print('name is not found in the file')

