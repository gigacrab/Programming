#File name : checkName.py

def Check(name1,name2):
    if name1.isalpha() and name2.isalpha():
        name=name1 + ' ' + name2
        return name
    else:
        return 'Error!,name should be only characters\n'
