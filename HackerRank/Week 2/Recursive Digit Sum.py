def super_digit(num):
    if num < 10:
        return num
    digit_sum = sum(int(d) for d in str(num))
    return super_digit(digit_sum)
n, k = input().split()
k = int(k)
initial_sum = sum(int(d) for d in n)
total_sum = initial_sum * k
print(super_digit(total_sum))