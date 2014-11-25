#pragma once
#include "Matrix3.h"

Matrix3::Matrix3(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3) {
	values[0][0] = x1;
	values[0][1] = y1;
	values[0][2] = z1;

	values[1][0] = x2;
	values[1][1] = y2;
	values[1][2] = z2;

	values[2][0] = x3;
	values[2][1] = y3;
	values[2][2] = z3;
}

Vector3 Matrix3::getColumn1() {
	Vector3 temp;
	temp.x = values[0][0];
	temp.y = values[0][1];
	temp.z = values[0][2];
	return temp;
}
Vector3 Matrix3::getColumn2() {
	Vector3 temp;
	temp.x = values[1][0];
	temp.y = values[1][1];
	temp.z = values[1][2];
	return temp;
}
Vector3 Matrix3::getColumn3() {
	Vector3 temp;
	temp.x = values[2][0];
	temp.y = values[2][1];
	temp.z = values[2][2];
	return temp;
}
Vector3 Matrix3::getRow1() {
	Vector3 temp;
	temp.x = values[0][0];
	temp.y = values[1][0];
	temp.z = values[2][0];
	return temp;
}
Vector3 Matrix3::getRow2() {
	Vector3 temp;
	temp.x = values[0][1];
	temp.y = values[1][1];
	temp.z = values[2][1];
	return temp;
}
Vector3 Matrix3::getRow3() {
	Vector3 temp;
	temp.x = values[0][2];
	temp.y = values[1][2];
	temp.z = values[2][2];
	return temp;
}

void Matrix3::Transpose() {
	Matrix3 temp;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			temp.values[i][j] = values[j][i];
		}
	}
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			values[i][j] = temp.values[i][j];
		}
	}
}
Vector3 Matrix3::MultiplyVector(Vector3 &vector) {
	Vector3 temp;
	temp.x = getRow1().dotProduct(vector);
	temp.y = getRow2().dotProduct(vector);
	temp.z = getRow3().dotProduct(vector);
	return temp;
}

Matrix3 Matrix3::operator * (Matrix3 &other) {
	Matrix3 temp;
	temp.values[0][0] = getRow1().dotProduct(other.getColumn1());
	temp.values[1][0] = getRow1().dotProduct(other.getColumn2());
	temp.values[2][0] = getRow1().dotProduct(other.getColumn3());

	temp.values[0][1] = getRow2().dotProduct(other.getColumn1());
	temp.values[1][1] = getRow2().dotProduct(other.getColumn2());
	temp.values[2][1] = getRow2().dotProduct(other.getColumn3());

	temp.values[0][2] = getRow3().dotProduct(other.getColumn1());
	temp.values[1][2] = getRow3().dotProduct(other.getColumn2());
	temp.values[2][2] = getRow3().dotProduct(other.getColumn3());
	return temp;
}
void Matrix3::operator *= (Matrix3 &other) {
	Matrix3 temp;
	temp.values[0][0] = getRow1().dotProduct(other.getColumn1());
	temp.values[1][0] = getRow1().dotProduct(other.getColumn2());
	temp.values[2][0] = getRow1().dotProduct(other.getColumn3());

	temp.values[0][1] = getRow2().dotProduct(other.getColumn1());
	temp.values[1][1] = getRow2().dotProduct(other.getColumn2());
	temp.values[2][1] = getRow2().dotProduct(other.getColumn3());

	temp.values[0][2] = getRow3().dotProduct(other.getColumn1());
	temp.values[1][2] = getRow3().dotProduct(other.getColumn2());
	temp.values[2][2] = getRow3().dotProduct(other.getColumn3());
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			values[i][j] = temp.values[i][j];
		}
	}
}
void Matrix3::operator = (Matrix3 &other) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			values[i][j] = other.values[i][j];
		}
	}
}
bool Matrix3::operator == (Matrix3 &other) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (values[i][j] != other.values[i][j])
				return false;
		}
	}
	return true;
}

//Transformation Matrices x3 -----------------------------
//Scale->Rotate->Translate

Matrix3 static CreateScaleM3(float X, float Y) {
	Matrix3 Return;
	Return.values[0][0] = X;
	Return.values[0][1] = 0;
	Return.values[0][2] = 0;

	Return.values[1][0] = 0;
	Return.values[1][1] = Y;
	Return.values[1][2] = 0;

	Return.values[2][0] = 0;
	Return.values[2][1] = 0;
	Return.values[2][2] = 1;
	return Return;
}
Matrix3 static CreateRotationM3(float radians) {
	Matrix3 Return;
	//float x = cosf(radians);
	//float y = sinf(radians + (Pi/2));

	Return.values[0][0] = cosf(radians);
	Return.values[0][1] = sinf(radians);
	Return.values[0][2] = 0;

	Return.values[1][0] = -sinf(radians);
	Return.values[1][1] = cosf(radians);
	Return.values[1][2] = 0;

	Return.values[2][0] = 0;
	Return.values[2][1] = 0;
	Return.values[2][2] = 1;

	return Return;
}
Matrix3 static CreateTranslationM3(float X, float Y) {
	Matrix3 Return;
	Return.values[0][0] = 1;
	Return.values[0][1] = 0;
	Return.values[0][2] = 0;

	Return.values[1][0] = 0;
	Return.values[1][1] = 1;
	Return.values[1][2] = 0;

	Return.values[2][0] = X;
	Return.values[2][1] = Y;
	Return.values[2][2] = 1;
	return Return;
}