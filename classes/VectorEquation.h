//
// Created by danan on 06/01/2024.
//

#ifndef LINALGCPP_VECTOREQUATION_H
#define LINALGCPP_VECTOREQUATION_H

#include "Vector.h"
const int VEC_EQ_PARAMS = 3;

class VectorEquation {
private:
    int dimension;
    Vector parameters[VEC_EQ_PARAMS];

    double scalarEq[MAX_SIZE];
    double scalarResult;
public:
    VectorEquation();
    VectorEquation(Vector const &point, Vector const &direction);
    VectorEquation(Vector const &point, Vector const &direction1, Vector const &direction2);

    friend std::ostream& operator<<(std::ostream &Out, VectorEquation const &eq);

    [[nodiscard]] Vector get_point() const { return parameters[0]; }
    [[nodiscard]] Vector get_direction1() const { return parameters[1]; }
    [[nodiscard]] Vector get_direction2() const { return parameters[2]; }

    void calc_line(Vector const &point1, Vector const &point2);
    void calc_plane_3_points(Vector const &point1, Vector const &point2, Vector const &point3);
    void calc_plane_line_point(const VectorEquation &line, const Vector &point);

    void calc_scalar_equation() const;
};

#endif //LINALGCPP_VECTOREQUATION_H
