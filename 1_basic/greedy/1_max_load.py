C = 30
arr = [4, 10, 7, 11, 3, 5, 14, 2]

def showList(arr):
    for i in arr:
        print(i, end=' ')
    print()

def main():
    # showList(arr)
    tmp = 0
    total = 0
    for i in sorted(arr):
        if (tmp + i) <= C:
            tmp += i
            total += 1
        else:
            break
    print(total)

if __name__ == "__main__":
    main()