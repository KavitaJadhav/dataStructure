#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_sorting_an_array_of_integers");
	setup();
		test_1_sorting_an_array_of_integers();
	tearDown();
	testEnded();
	testStarted("test_1_sorting_an_array_of_integers2");
	setup();
		test_1_sorting_an_array_of_integers2();
	tearDown();
	testEnded();
	testStarted("test_2_sorting_an_array_of_double");
	setup();
		test_2_sorting_an_array_of_double();
	tearDown();
	testEnded();
	testStarted("test_3_sorting_an_array_of_float");
	setup();
		test_3_sorting_an_array_of_float();
	tearDown();
	testEnded();
	testStarted("test_4_sorting_an_array_of_character");
	setup();
		test_4_sorting_an_array_of_character();
	tearDown();
	testEnded();
	testStarted("test_5_sorting_an_array_of_string");
	setup();
		test_5_sorting_an_array_of_string();
	tearDown();
	testEnded();
	testStarted("test_account_by_balance");
	setup();
		test_account_by_balance();
	tearDown();
	testEnded();
	testStarted("test_account_by_account_number");
	setup();
		test_account_by_account_number();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
