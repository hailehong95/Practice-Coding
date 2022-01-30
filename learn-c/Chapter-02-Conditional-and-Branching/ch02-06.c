#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define OPEN_TIME 8
#define CLOSE_TIME 24
#define PRICE 30000

int main()
{
	/*
	** Tính tiền Karaoke
	** - Nếu thời gia thuê <= 3h tính 30000 đồng/giờ (Giảm 0%)
	** - Nếu thời gian thuê > 3h tính 21000 đồng/giờ (Giảm 30%)
	** - Trong khung giờ vàng: 8h-17h: Giảm thêm 10% tổng số tiền
	** Quán Karaoke mở cửa từ: 8h00 - 24h00
	*/
	
	float start_time, end_time;
	printf("Start time = ");
	scanf("%f", &start_time);

	if (start_time < OPEN_TIME || start_time > CLOSE_TIME)
	{
		printf("Invalid start time!\n");
		return 1;
	}

	printf("End time = ");
	scanf("%f", &end_time);
	if (end_time <= start_time || end_time > CLOSE_TIME)
	{
		printf("Invalid end time!\n");
		return 2;
	}

	float time_to_use = end_time - start_time;

	if (start_time >= OPEN_TIME && end_time <= 17) // Khung giờ vàng từ 8h - 17h
	{
		if (time_to_use <= 3) // 3 giờ đầu
		{
			// Giảm 10% tổng tiền vì nằm trong khung giờ vàng
			float money = time_to_use * PRICE;
			float promotion = money * 0.1;
			printf("So tien phai tra: %.2f\n", money - promotion);
		}
		else // Thời gian thuê > 3
		{
			// km1: Giảm 30% mỗi giờ do thời gian > 3h
			// km2: Giảm 10% tổng tiền do khung giờ vàng
			float money = time_to_use * PRICE;
			float promotion1 = time_to_use * (0.3*PRICE);
			float promotion2 = (money - promotion1)*0.1;
			printf("So tien phai tra: %.2f\n", money - promotion1 - promotion2);
		}

	}
	else if (start_time > 17 && end_time <= CLOSE_TIME) // Khung giờ thường từ 18h - 24h
	{
		if (time_to_use <= 3) // 3 giờ đầu
		{
			// Khung giờ thường + <= 3h => Không có khuyến mại
			float money = time_to_use * PRICE;
			printf("So tien phai tra: %.2f\n", money);
		}
		else // Thời gian thuê > 3
		{
			// km1: Giảm 30% cho mỗi giờ vì thời gian thuê >3h
			float money = time_to_use * PRICE;
			float promotion = time_to_use * (0.3*PRICE);
			printf("Amount to be paid = %.2f\n", money - promotion);
		}
	}
	else // Khung giờ giữa khung vàng và khung thường
	{
		// Khung giờ này sẽ có đoạn thuộc giờ vàng và đoạn thuộc giờ thường
		float gold_time = 17 - start_time;
		float normal_time = end_time - 17;
		float total_price = (gold_time + normal_time) * PRICE;
		float km1, km2;

		if (gold_time <= 3)
			km1 = (PRICE * gold_time) * 0.1; // Khuyên mại 10%
		else
		{
			float km1_1 = PRICE * gold_time * 0.3; // Khuyến mại > 3h
			float km1_2 = ((gold_time * PRICE) - km1_1) * 0.1; // Khuyến mại Giờ vàng giảm 10%
			km1 = km1_1 + km1_2;
		}

		if (normal_time <= 3)
			km2 = 0;
		else
			km2 = normal_time * PRICE * 0.3;

		printf("Amount to be paid = %.2f\n", total_price - km1 - km2);
	}

	return 0;
} 