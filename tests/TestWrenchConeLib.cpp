// wrenh-cone-lib: computes a Contact Wrench Cone using polyhedral presentation
// Copyright (C) 2019 Vincent Samy

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestWrenchConeLib

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <boost/test/unit_test.hpp>

#include <wcl/WrenchCone.h>
#include <wcl/ContactSurface.h>

BOOST_AUTO_TEST_CASE(HUMANOID_FEET)
{
    // Positions
    Eigen::Vector3d com(Eigen::Vector3d::Zero());
    Eigen::Vector3d lf(0.2, 0.15, 0.1);
    Eigen::Vector3d rf(-0.4, 0, 0);

    // Orientations
    Eigen::Matrix3d E_0_lf = Eigen::AngleAxisd(0.4, Eigen::Vector3d::UnitX()).toRotationMatrix();
    Eigen::Matrix3d E_0_rf = Eigen::AngleAxisd(-0.4, Eigen::Vector3d::UnitX()).toRotationMatrix();

    // Contact info
    double mu = 0.5;
    int nrg = 4;

    // Contact surface
    auto cLf = wcl::rectangularSurface(0.11, 0.05, lf, E_0_lf, mu, nrg);
    auto cRf = wcl::rectangularSurface(0.11, 0.05, rf, E_0_rf, mu, nrg);

    wcl::WrenchCone wrenchCone(com, { cLf, cRf });
    auto raysMat = wrenchCone.getRays();
    auto hfMat = wrenchCone.getHalfspaces();
    BOOST_CHECK(true);
}
