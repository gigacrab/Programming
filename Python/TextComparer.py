text1 = """"""
text2 = """"""

following = text1.split("\n")
followers = text2.split("\n")

delete = []

for f in following:
    if f in followers:
        delete.append(f)

for i in delete:
    following.remove(i)

for f in following:
    print(f)
print(f"!generally people have names on their profile so roughly {int(len(following)/2)} dont follow you back :)")