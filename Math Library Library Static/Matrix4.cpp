#pragma once
#include "Matrix4.h"

Matrix4::Matrix4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float a1, float a2, float a3, float a4) {
	values[0][0] = x1;
	values[0][1] = y1;
	values[0][2] = z1;
	values[0][3] = a1;

	values[1][0] = x2;
	values[1][1] = y2;
	values[1][2] = z2;
	values[1][3] = a2;

	values[2][0] = x3;
	values[2][1] = y3;
	values[2][2] = z3;
	values[2][3] = a3;

	values[3][0] = x4;
	values[3][1] = y4;
	values[3][2] = z4;
	values[3][3] = a4;
}

Vector4 Matrix4::getColumn1() {
	Vector4 temp;
	temp.x = values[0][0];
	temp.y = values[0][1];
	temp.z = values[0][2];
	temp.a = values[0][3];
	return temp;
}
Vector4 Matrix4::getColumn2() {
	Vector4 temp;
	temp.x = values[1][0];
	temp.y = values[1][1];
	temp.z = values[1][2];
	temp.a = values[1][3];
	return temp;
}
Vector4 Matrix4::getColumn3() {
	Vector4 temp;
	temp.x = values[2][0];
	temp.y = values[2][1];
	temp.z = values[2][2];
	temp.a = values[2][3];
	return temp;
}
Vector4 Matrix4::getColumn4() {
	Vector4 temp;
	temp.x = values[3][0];
	temp.y = values[3][1];
	temp.z = values[3][2];
	temp.a = values[3][3];
	return temp;
}
Vector4 Matrix4::getRow1() {
	Vector4 temp;
	temp.x = values[0][0];
	temp.y = values[1][0];
	temp.z = values[2][0];
	temp.a = values[3][0];
	return temp;
}
Vector4 Matrix4::getRow2() {
	Vector4 temp;
	temp.x = values[0][1];
	temp.y = values[1][1];
	temp.z = values[2][1];
	temp.a = values[3][1];
	return temp;
}
Vector4 Matrix4::getRow3() {
	Vector4 temp;
	temp.x = values[0][2];
	temp.y = values[1][2];
	temp.z = values[2][2];
	temp.a = values[3][2];
	return temp;
}
Vector4 Matrix4::getRow4() {
	Vector4 temp;
	temp.x = values[0][3];
	temp.y = values[1][3];
	temp.z = values[2][3];
	temp.a = values[3][3];
	return temp;
}

void Matrix4::Transpose() {
	Matrix4 temp;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			temp.values[i][j] = values[j][i];
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			values[i][j] = temp.values[i][j];
		}
	}
}
Vector4 Matrix4::MultiplyVector(Vector4 &vector) {
	Vector4 temp;
	temp.x = getRow1().dotProduct(vector);
	temp.y = getRow2().dotProduct(vector);
	temp.z = getRow3().dotProduct(vector);
	temp.a = getRow4().dotProduct(vector);
	return temp;
}

Matrix4 Matrix4::operator * (Matrix4 &other) {
	Matrix4 temp;
	temp.values[0][0] = getRow1().dotProduct(other.getColumn1());
	temp.values[1][0] = getRow1().dotProduct(other.getColumn2());
	temp.values[2][0] = getRow1().dotProduct(other.getColumn3());
	temp.values[3][0] = getRow1().dotProduct(other.getColumn4());

	temp.values[0][1] = getRow2().dotProduct(other.getColumn1());
	temp.values[1][1] = getRow2().dotProduct(other.getColumn2());
	temp.values[2][1] = getRow2().dotProduct(other.getColumn3());
	temp.values[3][1] = getRow2().dotProduct(other.getColumn4());

	temp.values[0][2] = getRow3().dotProduct(other.getColumn1());
	temp.values[1][2] = getRow3().dotProduct(other.getColumn2());
	temp.values[2][2] = getRow3().dotProduct(other.getColumn3());
	temp.values[3][2] = getRow3().dotProduct(other.getColumn4());

	temp.values[0][3] = getRow4().dotProduct(other.getColumn1());
	temp.values[1][3] = getRow4().dotProduct(other.getColumn2());
	temp.values[2][3] = getRow4().dotProduct(other.getColumn3());
	temp.values[3][3] = getRow4().dotProduct(other.getColumn4());
	return temp;
}
void Matrix4::operator *= (Matrix4 &other) {
	Matrix4 temp;
	values[0][0] = getRow1().dotProduct(other.getColumn1());
	values[1][0] = getRow1().dotProduct(other.getColumn2());
	values[2][0] = getRow1().dotProduct(other.getColumn3());
	values[3][0] = getRow1().dotProduct(other.getColumn4());

	values[0][1] = getRow2().dotProduct(other.getColumn1());
	values[1][1] = getRow2().dotProduct(other.getColumn2());
	values[2][1] = getRow2().dotProduct(other.getColumn3());
	values[3][1] = getRow2().dotProduct(other.getColumn4());

	values[0][2] = getRow3().dotProduct(other.getColumn1());
	values[1][2] = getRow3().dotProduct(other.getColumn2());
	values[2][2] = getRow3().dotProduct(other.getColumn3());
	values[3][2] = getRow3().dotProduct(other.getColumn4());

	values[0][3] = getRow4().dotProduct(other.getColumn1());
	values[1][3] = getRow4().dotProduct(other.getColumn2());
	values[2][3] = getRow4().dotProduct(other.getColumn3());
	values[3][3] = getRow4().dotProduct(other.getColumn4());
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			values[i][j] = temp.values[i][j];
		}
	}
}
void Matrix4::operator = (Matrix4 &other) {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			values[i][j] = other.values[i][j];
		}
	}
}
bool Matrix4::operator == (Matrix4 &other) {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (values[i][j] != other.values[i][j])
				return false;
		}
	}
	return true;
}

//Transformation Matrices x4 -----------------------------------
//Scale->Rotate->Translate

Matrix4 static CreateScaleM4(float X, float Y, float Z) {
	Matrix4 Return;
	Return.values[0][0] = X;
	Return.values[0][1] = 0;
	Return.values[0][2] = 0;
	Return.values[0][3] = 0;

	Return.values[1][0] = 0;
	Return.values[1][1] = Y;
	Return.values[1][2] = 0;
	Return.values[1][3] = 0;

	Return.values[2][0] = 0;
	Return.values[2][1] = 0;
	Return.values[2][2] = Z;
	Return.values[2][3] = 0;

	Return.values[3][0] = 0;
	Return.values[3][1] = 0;
	Return.values[3][2] = 0;
	Return.values[3][3] = 1;
	return Return;
}

Matrix4 static CreateXRotationM4(float Xradians) {
	Matrix4 tempX;
	tempX.values[0][0] = 1;
	tempX.values[0][1] = 0;
	tempX.values[0][2] = 0;
	tempX.values[0][3] = 0;

	tempX.values[1][0] = 0;
	tempX.values[1][1] = cosf(Xradians);
	tempX.values[1][2] = sinf(Xradians);
	tempX.values[1][3] = 0;

	tempX.values[2][0] = 0;
	tempX.values[2][1] = -sinf(Xradians);
	tempX.values[2][2] = cosf(Xradians);
	tempX.values[2][3] = 0;

	tempX.values[3][0] = 0;
	tempX.values[3][1] = 0;
	tempX.values[3][2] = 0;
	tempX.values[3][3] = 1;
	return tempX;
}
Matrix4 static CreateYRotationM4(float Yradians) {
	Matrix4 tempY;
	tempY.values[0][0] = cosf(Yradians);
	tempY.values[0][1] = 0;
	tempY.values[0][2] = -sinf(Yradians);
	tempY.values[0][3] = 0;

	tempY.values[1][0] = 0;
	tempY.values[1][1] = 1;
	tempY.values[1][2] = 0;
	tempY.values[1][3] = 0;

	tempY.values[2][0] = sinf(Yradians);
	tempY.values[2][1] = 0;
	tempY.values[2][2] = cosf(Yradians);
	tempY.values[2][3] = 0;

	tempY.values[3][0] = 0;
	tempY.values[3][1] = 0;
	tempY.values[3][2] = 0;
	tempY.values[3][3] = 1;
	return tempY;
}
Matrix4 static CreateZRotationM4(float Zradians) {
	Matrix4 tempZ;
	tempZ.values[0][0] = cosf(Zradians);
	tempZ.values[0][1] = sinf(Zradians);
	tempZ.values[0][2] = 0;
	tempZ.values[0][3] = 0;

	tempZ.values[1][0] = -sinf(Zradians);
	tempZ.values[1][1] = cosf(Zradians);
	tempZ.values[1][2] = 0;
	tempZ.values[1][3] = 0;

	tempZ.values[2][0] = 0;
	tempZ.values[2][1] = 0;
	tempZ.values[2][2] = 1;
	tempZ.values[2][3] = 0;

	tempZ.values[3][0] = 0;
	tempZ.values[3][1] = 0;
	tempZ.values[3][2] = 0;
	tempZ.values[3][3] = 1;
	return tempZ;
}

Matrix4 static CreateTranslationM4(float X, float Y, float Z) {
	Matrix4 Return;
	Return.values[0][0] = 1;
	Return.values[0][1] = 0;
	Return.values[0][2] = 0;
	Return.values[0][3] = 0;

	Return.values[1][0] = 0;
	Return.values[1][1] = 1;
	Return.values[1][2] = 0;
	Return.values[1][3] = 0;

	Return.values[2][0] = 0;
	Return.values[2][1] = 0;
	Return.values[2][2] = 1;
	Return.values[2][3] = 0;

	Return.values[3][0] = X;
	Return.values[3][1] = Y;
	Return.values[3][2] = Z;
	Return.values[3][3] = 1;
	return Return;
}

// Orthographic Projection Matrix ----------------------
Matrix4 static OrthographicProjectionMatrix(float right, float left, float top, float bottom, float far, float near) {
	Matrix4 Return;
	Return.values[0][0] = 2 / (right - left);
	Return.values[0][1] = 0;
	Return.values[0][2] = 0;
	Return.values[0][3] = 0;

	Return.values[1][0] = 0;
	Return.values[1][1] = 2 / (top - bottom);
	Return.values[1][2] = 0;
	Return.values[1][3] = 0;

	Return.values[2][0] = 0;
	Return.values[2][1] = 0;
	Return.values[2][2] = -2 / (far - near);
	Return.values[2][3] = 0;

	Return.values[3][0] = -((right + left) / (right - left));
	Return.values[3][1] = -((top + bottom) / (top - bottom));
	Return.values[3][2] = ((far + near) / (far - near));
	Return.values[3][3] = 1;
	return Return;
}