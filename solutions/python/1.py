max_number = 1000
sum = 0

for x in range(0, max_number):
  if x % 3 == 0 or x % 5 == 0:
    sum += x

print("Sum of all multiples of 3 or 5 below " + str(max_number) + ": " + str(sum))

