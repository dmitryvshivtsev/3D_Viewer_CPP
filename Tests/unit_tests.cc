#include <gtest/gtest.h>

#include "../Model/s21_model.h"


TEST(Test_1, LoadObject_1) {
  s21::ObjectParser* test = s21::ObjectParser::ParserInstance();
  std::string path = "objs/test.obj";
  test->MainParser(path);
  EXPECT_EQ(test->GetV().size() / 3, 3);
}

TEST(Test_1, LoadObject_2) {
  s21::ObjectParser* test = s21::ObjectParser::ParserInstance();
  std::string path = "objs/testf.obj";
  EXPECT_THROW(test->MainParser(path), std::invalid_argument);
}

TEST(Test_1, LoadObject_3) {
  s21::ObjectParser* test = s21::ObjectParser::ParserInstance();
  std::string path = "objs/test.obj";
  test->MainParser(path);
  EXPECT_EQ(test->GetF()[0], 0);
  EXPECT_EQ(test->GetF()[1], 1);
  EXPECT_EQ(test->GetF()[2], 1);
  EXPECT_EQ(test->GetF()[3], 2);
  EXPECT_EQ(test->GetF()[4], 2);
  EXPECT_EQ(test->GetF()[5], 0);
}

TEST(Test_1, LoadObject_4) {
  s21::ObjectParser* test = s21::ObjectParser::ParserInstance();
  std::string path = "objs/test.obj";
  test->MainParser(path);
  EXPECT_EQ(test->GetMinMax().first, 1);
  EXPECT_EQ(test->GetMinMax().second, 9);
}

TEST(Test_2, Move_1) {
  s21::Model *test = s21::Model::ModelInstance();
  std::map<std::string, double> move = {{"x", 3}, {"y", 0}, {"z", 0}};
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->MoveModel(move);
  EXPECT_EQ(test->GetTransformV()[0], 4);
}

TEST(Test_2, Move_2) {
  s21::Model *test = s21::Model::ModelInstance();
  std::map<std::string, double> move = {{"x", 0}, {"y", -3}, {"z", 0}};
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->MoveModel(move);
  EXPECT_EQ(test->GetTransformV()[1], -1);
}

TEST(Test_2, Move_3) {
  s21::Model *test = s21::Model::ModelInstance();
  std::map<std::string, double> move = {{"x", 0}, {"y", 0}, {"z", 3.3}};
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->MoveModel(move);
  EXPECT_EQ(test->GetTransformV()[6], 7);
}

TEST(Test_3, Rotation_1) {
  s21::Model *test = s21::Model::ModelInstance();
  std::map<std::string, double> move = {{"x", 3}, {"y", 0}, {"z", 0}};
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->RotationModel(move);
  EXPECT_DOUBLE_EQ(test->GetTransformV()[2], -3.2522175059210707);
}

TEST(Test_3, Rotation_2) {
  s21::Model *test = s21::Model::ModelInstance();
  std::map<std::string, double> move = {{"x", 0}, {"y", 3.9}, {"z", 0}};
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->RotationModel(move);
  EXPECT_DOUBLE_EQ(test->GetTransformV()[6], -11.271421562056744);
}

TEST(Test_3, Rotation_3) {
  s21::Model *test = s21::Model::ModelInstance();
  std::map<std::string, double> move = {{"x", 0}, {"y", 0}, {"z", -4}};
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->RotationModel(move);
  EXPECT_DOUBLE_EQ(test->GetTransformV()[4], -6.2954280855497728);
}

TEST(Test_4, Zoom_1) {
  s21::Model *test = s21::Model::ModelInstance();
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->ZoomModel(3);
  EXPECT_EQ(test->GetTransformV()[7], 24);
}

TEST(Test_4, Zoom_2) {
  s21::Model *test = s21::Model::ModelInstance();
  std::string path = "objs/test.obj";
  test->Begin(path);
  test->ZoomModel(0.5);
  EXPECT_EQ(test->GetTransformV()[2], 1.5);
}

TEST(Test_5, EdgeCount_1) {
  s21::Model *test = s21::Model::ModelInstance();
  std::string path = "objs/test.obj";
  test->Begin(path);
  EXPECT_DOUBLE_EQ(test->GetEdge(), 11);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
