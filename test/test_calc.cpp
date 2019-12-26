#include "stack.h"

#include <gtest.h>

TEST(Calculator, can_create_postfix)
{
	ASSERT_NO_THROW(Calculator p);
}

TEST(Calculator, can_get_expression)
{
	Calculator p;
	p.SetExpr("1+1");
	EXPECT_EQ("1+1", p.GetExpr());
}

TEST(Calculator, can_check_brackets)
{
	Calculator p;
	p.SetExpr("(1+1(");
	EXPECT_EQ(false, p.CheckBrackets());
}

TEST(Calculator, can_create_right_postfix)
{
	Calculator p;
	p.SetExpr("1+1");
	EXPECT_EQ("1 1 +", p.ToPostfix());
}

TEST(Calculator, can_calculate_postfix)
{
	Calculator p;
	p.SetExpr("1+1");
	p.ToPostfix();
	EXPECT_EQ(2, p.Calculate());
}
TEST(Calculator, can_sub_postfix)
{
	Calculator p;
	p.SetExpr("10-6");
	p.ToPostfix();
	EXPECT_EQ(4, p.Calculate());
}
TEST(Calculator, can_mul_postfix)
{
	Calculator p;
	p.SetExpr("5*3");
	p.ToPostfix();
	EXPECT_EQ(15, p.Calculate());
}
TEST(Calculator, can_div_postfix)
{
	Calculator p;
	p.SetExpr("100/5");
	p.ToPostfix();
	EXPECT_EQ(20, p.Calculate());
}
TEST(Calculator, can_compl_comp_expr_postfix)
{
	Calculator p;
	p.SetExpr("(100/5)*(6-4)/10");
	p.ToPostfix();
	EXPECT_EQ(4, p.Calculate());
}

