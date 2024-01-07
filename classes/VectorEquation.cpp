//
// Created by danan on 06/01/2024.
//

#include "VectorEquation.h"

VectorEquation::VectorEquation() {
    dimension = 2;
    for (int i = 0; i < VEC_EQ_PARAMS; i++)
        parameters[i] = Vector(2);
}

VectorEquation::VectorEquation(Vector const &point, Vector const &direction) {
    if (point.get_dimension() != direction.get_dimension()) {
        std::cout << "Cannot form vector equation; vectors have different dimensions";
        (*this) = VectorEquation();
    }

    parameters[0] = point;
    parameters[1] = direction;
    parameters[2] = Vector(point.get_dimension());
    dimension = point.get_dimension();
}

VectorEquation::VectorEquation(Vector const &point, Vector const &direction1, Vector const &direction2) {
    if (! (point.get_dimension() == direction1.get_dimension() &&
           point.get_dimension() == direction2.get_dimension()) )
    {
        std::cout << "Cannot form vector equation; vectors have different dimensions";
        (*this) = VectorEquation();
    }

    parameters[0] = point;
    parameters[1] = direction1;
    parameters[2] = direction2;
    dimension = point.get_dimension();
}

std::ostream& operator<<(std::ostream &Out, VectorEquation const &eq) {
    Out << eq.parameters[0] << " + s*" << eq.parameters[1];
    if (eq.parameters[2].get_norm() != 0)
        Out << " + t*" << eq.parameters[2];
    return Out;
}

void VectorEquation::calc_line(const Vector &point1, const Vector &point2) {
    parameters[0] = point1;
    parameters[1] = point2 - point1;
}

void VectorEquation::calc_plane_3_points(const Vector &point1, const Vector &point2, const Vector &point3) {
    parameters[0] = point1;
    parameters[1] = point2 - point1;
    parameters[2] = point3 - point1;
}

void VectorEquation::calc_plane_line_point(const VectorEquation &line, const Vector &point) {
    parameters[0] = point;
    parameters[1] = line.get_direction1();
    parameters[2] = point - line.get_point();
}