import os
import time

NUM_OF_TESTCASE = len(os.listdir("tc/")) -1
wrong = 0
wrong_tcs = []
bar = NUM_OF_TESTCASE*10
t1 = time.time()


ops = ["solutions/SocialNetwork.cpp","solutions/Post.cpp", "solutions/Profile.cpp"]

print(bar * '.',end = '')
print("0%",end = '\r')

for i in ops:
	os.system("g++ -c -ansi -Wall -pedantic-errors -O0 -std=c++11 " + i)

for i in range(1,NUM_OF_TESTCASE+1):
	os.system("g++ -c -ansi -Wall -pedantic-errors -O0 -std=c++11 tc/testcase" + str(i) + ".cpp")


for i in range(1,NUM_OF_TESTCASE+1):
	time.sleep(0.2)
	tc = "testcase"+str(i)+".o"
	outp = "out/output"+str(i)+".txt"
	expe = "exp/expected"+str(i)+".txt"

	
	os.system("g++ -o a " + tc + " SocialNetwork.o Profile.o Post.o")

	os.system("./a  >"+outp)

	output = open(outp,"r+")
	out = output.read()

	expected = open(expe,"r+")
	exp = expected.read()

	if(exp != out):
		print( "Testcase"+str(i)+" Failed!\n")
		print("Correct Output:\n"+exp)
		print("\nYour Output:\n"+out)
		wrong_tcs.append("Testcase"+str(i))
		wrong+=1


	progress = int((i/NUM_OF_TESTCASE)*bar)
	percantage = round((progress*100)/bar,1)
	print(progress*'#',end='')
	print((bar-progress)*'.',end = '')
	print(str(percantage)+ "%",end='\r')

os.system("rm *.o")
os.system("rm a")
print("\nYou failed " + str(wrong) + " times on "+str(NUM_OF_TESTCASE)+" testcases.")
print("You failed on the cases: {}".format(wrong_tcs))
t2 = time.time()
t2 -= 3
print("Execute time is: {}".format(t2-t1))
