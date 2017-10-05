/*      File: utils.h
*       This file is part of the program wrench-cone-lib
*       Program description : This library implements the Contact Wrench Cone as given [here](https://scaron.info/papers/journal/caron-tro-2016.pdf). It uses cdd for the polyhedron computation and Eigen for the matrix part. Python bindings are also available.
*       Copyright (C) 2017 -  Vincent Samy (LIRMM). All Right reserved.
*
*       This software is free software: you can redistribute it and/or modify
*       it under the terms of the CeCILL-C license as published by
*       the CEA CNRS INRIA, either version 1
*       of the License, or (at your option) any later version.
*       This software is distributed in the hope that it will be useful,
*       but WITHOUT ANY WARRANTY without even the implied warranty of
*       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*       CeCILL-C License for more details.
*
*       You should have received a copy of the CeCILL-C License
*       along with this software. If not, it can be found on the official website
*       of the CeCILL licenses family (http://www.cecill.info/index.en.html).
*/
#pragma once

#include <Eigen/Core>
#include <wcl/ContactSurface.h>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <vector>

namespace np = boost::python::numpy;
namespace py = boost::python;

namespace wcl {
Eigen::Vector3d extractV3d(const np::ndarray& v);
Eigen::Matrix3d extractM3d(const np::ndarray& m);
std::vector<ContactSurface> extractCSList(const py::list& py_pCSs);
std::vector<Eigen::Vector3d> extractPointsList(const py::list& py_points);
np::ndarray buildNumpyArray(const Eigen::MatrixXd& mat);
}
