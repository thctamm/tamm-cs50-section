from student import Student

tim = Student("Tim")
lisa = Student("Lisa")

tim.addGrade('A')
tim.addGrade('B')
tim.addGrade('B')
tim.addGrade('A')

tim.addGrade('E')
tim.addGrade('P')

lisa.addGrade('C')
lisa.addGrade('B')
lisa.addGrade('A')
lisa.addGrade('A')
lisa.addGrade('A')
lisa.addGrade('A')

print("{0}'s GPA is: {1}".format(tim.getName(), tim.getGpa()))
print("{0}'s GPA is: {1}".format(lisa.getName(), lisa.getGpa()))
