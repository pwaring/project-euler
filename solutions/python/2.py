max_number = 4000000
fib_sequence = [1, 1, 2]
total = 0

while fib_sequence[2] <= max_number:
  if fib_sequence[2] % 2 == 0:
      total += fib_sequence[2]

  # Move all elements back one place and recalculate the 3rd
  fib_sequence[0] = fib_sequence[1]
  fib_sequence[1] = fib_sequence[2]
  fib_sequence[2] = fib_sequence[0] + fib_sequence[1]

print("Total of all even Fibonnaci numbers up to " + str(max_number) + " is: " + str(total))
