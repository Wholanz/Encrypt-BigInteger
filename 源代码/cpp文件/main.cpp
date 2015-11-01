#include "BigInteger.h"
using namespace std;

BigInteger encrypt(BigInteger X ,BigInteger p, BigInteger a);
BigInteger decrypt(BigInteger X, BigInteger p, BigInteger Y);

void BigIntegerTest();
void DH_algorithm();

int main(){
	
	int sel;

	while (true){

		cout << "Choose a number to select what you want to do:" << endl;
		cout << "1. Test BigInteger operation." << endl;
		cout << "2. DH algorithm." << endl;
		cout << "3. Exit." << endl;

		cin >> sel;

		switch (sel){
		
		case 3:
			exit(0);
			break;
		case 1:
			BigIntegerTest();
			break;
		case 2:
			DH_algorithm();
			break;
		}

	}


	
	return 0;
}

BigInteger encrypt(BigInteger X, BigInteger p, BigInteger a){

	BigInteger Y;

	Y = a.powMod(X, p);

	return Y;

}
BigInteger decrypt(BigInteger X, BigInteger p, BigInteger Y){

	BigInteger key;

	key = Y.powMod(X, p);

	return key;
}

void BigIntegerTest(){

	BigInteger op1, op2, result;

	cout << "************************************************************************" << endl;
	cout << "Welcome!" << endl;
	cout << "Enter two oprands and an operation to get the result" << endl;
	cout << "Or Enter \"quit\" to exit" << endl;
	cout << "************************************************************************" << endl;

	string input = "";

	do{

		cout << "Input the first oprand or \"quit\" to exit" << endl;
		cin >> input;
		if (input == "quit"){
			break;
		}
		else{
			try{
				op1 = input;
			}
			catch (BigIntegerError e){
				cerr << "Runtime error : " << e.what() << endl;
				continue;
			}
		}
		cout << "Input the second oprand or \"quit\" to exit" << endl;
		cin >> input;
		if (input == "quit"){
			break;
		}
		else{
			try{
				op2 = input;
			}
			catch (BigIntegerError e){
				cerr << "Runtime error : " << e.what() << endl;
				continue;
			}
		}


		cout << "Input operation(+ - * / % ^) or \"quit\" to exit" << endl;
		cin >> input;
		if (input == "quit"){
			break;
		}
		else if (input.length() == 1){
			switch (input.at(0)){
			case '+':
				result = op1 + op2;
				cout << op1 << input << op2 << "=" << result << endl;
				break;
			case '-':
				result = op1 - op2;
				cout << op1 << input << op2 << "=" << result << endl;
				break;
			case '*':
				result = op1 * op2;
				cout << op1 << input << op2 << "=" << result << endl;
				break;
			case '/':
				result = op1 / op2;
				cout << op1 << input << op2 << "=" << result << endl;
				break;
			case '%':
				try{
					result = op1 % op2;
				}
				catch (BigIntegerError e){
					cerr << "Runtime error : " << e.what() << endl;
					continue;
				}
				cout << op1 << input << op2 << "=" << result << endl;
				break;

			case '^':
				result = op1 ^ op2;
				cout << op1 << input << op2 << "=" << result << endl;
				break;

			default:

				cout << "Wrong operation!" << endl;

			}

		}
		else {
			cout << "Wrong operation!" << endl;
		}

	} while (true);
	cout << "Thanks!" << endl;
	system("pause");
	return ;


}

void DH_algorithm(){

	BigInteger XA, XB;
	
	BigInteger a, p;

	BigInteger YA, YB;

	BigInteger KA,KB;

	cout << "欢迎使用DH算法!" << endl;
	
	cout << "请输入一个大素数:" << endl;
	cin >> p;
	
	cout << "请输入大素数的一个原根:" << endl;
	cin >> a;
	
	cout << "请用户A选择一个小于大素数：" << p << "的私钥" << endl;
	cin >> XA;

	cout << "请用户B选择一个小于大素数： " << p << "的私钥" << endl;
	cin >>XB;

	

	YA =  encrypt(XA, p, a);
	YB =  encrypt(XB, p, a);

	
	KA = decrypt(XA, p, YB);
	KB = decrypt(XB, p, YA);

	cout << "用户B向用户A发送公开秘钥 YB： " << YB << endl;
	cout << "用户A向用户B发送公开秘钥 YA： " << YA << endl;

	cout << "解密后的秘钥KA为： " << KA << endl;
	cout << "解密后的秘钥KB为： " << KB << endl;

	cout << "感谢您的使用！" << endl;

	cout << "*****************************************************" << endl;

}