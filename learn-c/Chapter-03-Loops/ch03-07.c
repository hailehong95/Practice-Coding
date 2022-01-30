#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// Mật khẩu chỉ hiển thị ký tự *
	char c = 'h', password[20]; // Khởi tạo cho c là một ký tự bất kỳ
	int i = 0;

	printf("Password: ");
	while (c != 13) {
		if (kbhit()) {
			// kbhit(): trả về True nếu phím được ấn
			c = getch(); // Đợi nhập 1 ký tự
			if (c != 8) {
				// Không phải phím xóa
				printf("*");
				// Lưu từng ký tự nhập vào mảng
				password[i] = c;
				i++;
			}
			else {
				printf("\b \b");
				i--;
				password[i] = '\0';
			}
		}
	}
	password[i] = '\0'; // Thêm kí tự kết thúc chuỗi
	printf("\nPassword is: %s\n", password);

	return 0;
}