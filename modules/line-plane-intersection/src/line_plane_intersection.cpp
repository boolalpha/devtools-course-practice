// Copyright 2018 Kulikova Svetlana

#include "include/line_plane_intersection.h"

LinePlaneIntersection::LinePlaneIntersection() :
    NotIntersectPlaneLine(true) {}

dot LinePlaneIntersection::CreateVector(dot A, dot B) {
    dot CreateVector;

    CreateVector.x = B.x - A.x;
    CreateVector.y = B.y - A.y;
    CreateVector.z = B.z - A.z;

    return CreateVector;
}

dot LinePlaneIntersection::VectorProduct(dot A, dot B) {
    dot VP;

    VP.x = A.y * B.z - B.y * A.z;
    VP.y = A.z * B.x - B.z * A.x;
    VP.z = A.x * B.y - B.x * A.y;

    return VP;
}

double LinePlaneIntersection::DotProduct(dot A, dot B) {
    double SP;

    SP = A.x * B.x + A.y * B.y + A.z * B.z;

    return SP;
}

void LinePlaneIntersection::Normalize(dot A) {
    double mlr;

    mlr = sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    A.x = A.x / mlr;
    A.y = A.y / mlr;
    A.z = A.z / mlr;
}

bool LinePlaneIntersection::IncorrectLine(dot A, dot B) {
    if (A.x == B.x && A.y == B.y && A.z == B.z)
        return true;
    return false;
}

bool LinePlaneIntersection::IncorrectPlane(dot A, dot B, dot C) {
    if (A.x == B.x && A.y == B.y && A.z == B.z)
        return true;
    if (A.x == C.x && A.y == C.y && A.z == C.z)
        return true;
    if (C.x == B.x && C.y == B.y && C.z == B.z)
        return true;
    return false;
}

dot LinePlaneIntersection::PlaneIntersectLine(dot A,
    dot B, dot C, dot X, dot Y) {
    dot N, V, W, PlaneIntersectLine = { 0, 0, 0 };
    double e, d;

    NotIntersectPlaneLine = true;

    if (IncorrectLine(X, Y))
        throw "Incorrect Line";

    if (IncorrectPlane(A, B, C))
        throw "Incorrect Plane";

    N = VectorProduct(CreateVector(A, B), CreateVector(A, C));
    Normalize(N);
    V = CreateVector(X, A);
    d = DotProduct(N, V);
    W = CreateVector(X, Y);
    e = DotProduct(N, W);

    if (e != 0) {
        PlaneIntersectLine.x = X.x + W.x * d / e;
        PlaneIntersectLine.y = X.y + W.y * d / e;
        PlaneIntersectLine.z = X.z + W.z * d / e;
        NotIntersectPlaneLine = false;
    }

    return PlaneIntersectLine;
}

bool LinePlaneIntersection::GetNotIntersectPlaneLine() {
    return NotIntersectPlaneLine;
}
