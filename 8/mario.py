# Initialize a height variable
height = -1
# Ask the user for a height that is within bounds
while i < 0 or i > 24:
    height = int(input("how high?"))
# Print out the pyramid
for r in range(height):
    print(" " * (height-r-1) + "#" * (2*r+2))
