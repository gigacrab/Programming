import time

def pascals_down(index):
    list = []
    list.append([1])
    for i in range(1, index + 1):
        if (i > 1):
            list.append([1])
            for n in range(0, i - 2):
                list[i - 1].append(list[i - 2][n] + list[i - 2][n + 1])
            list[i - 1].append(1)
    output = list
    return output

def pascals_up(index):
    if index == 1:
        list = [1]
        print(list)
        return list
    else:
        prev_list = pascals_up(index - 1)
        list = [1]
        for i in range(0, index - 2):
            list.append(prev_list[i + 1] + prev_list[i])
        list.append(1)
        print(list)
        return list

count = int(input("Enter count amount: "))
start_time_up = time.time()

for i in pascals_down(count):
    print(i)
print("Upwards time: ", time.time() - start_time_up)

start_time_down = time.time()
pascals_up(count)
print("Downwards time: ", time.time() - start_time_down)