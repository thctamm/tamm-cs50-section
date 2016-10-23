class Student():

    def __init__(self, name):
        self.name = name
        self.gradeSum = 0
        self.numGrades = 0

    def getGpa(self):
        return self.gradeSum/self.numGrades

    def addGrade(self, grade):
        if grade == 'A':
            self.gradeSum += 4
            self.numGrades += 1
        elif grade == 'B':
            self.gradeSum += 3
            self.numGrades += 1
        elif grade == 'C':
            self.gradeSum += 2
            self.numGrades += 1
        elif grade == 'D':
            self.gradeSum += 1
            self.numGrades += 1
        elif grade == 'E' or grade == 'F':
            self.numGrades += 1
        else:
            print("Invalid grade")

    def getName(self):
        return self.name
