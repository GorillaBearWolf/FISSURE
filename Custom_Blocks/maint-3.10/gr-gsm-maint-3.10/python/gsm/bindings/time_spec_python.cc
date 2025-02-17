/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(misc_utils/time_spec.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(e62de679872f902011edd693e08dbe84)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gsm/misc_utils/time_spec.h>
// pydoc.h is automatically generated in the build directory
#include <time_spec_pydoc.h>

void bind_time_spec(py::module& m)
{

    using time_spec_t    = ::gr::gsm::time_spec_t;


    py::class_<time_spec_t, boost::operators_impl::additive<gr::gsm::time_spec_t, gr::gsm::time_spec_t, boost::operators_impl::operators_detail::empty_base<gr::gsm::time_spec_t>, boost::operators_impl::operators_detail::false_t>,
        std::shared_ptr<time_spec_t>>(m, "time_spec_t", D(time_spec_t))

        .def(py::init<gr::gsm::time_spec_t const &>(),           py::arg("spec"),
           D(time_spec_t,time_spec_t,0)
        )
        .def(py::init<double>(),           py::arg("secs") = 0,
           D(time_spec_t,time_spec_t,1)
        )
        .def(py::init<time_t,double>(),           py::arg("full_secs"),
           py::arg("frac_secs") = 0,
           D(time_spec_t,time_spec_t,2)
        )
        .def(py::init<time_t,long int,double>(),           py::arg("full_secs"),
           py::arg("tick_count"),
           py::arg("tick_rate"),
           D(time_spec_t,time_spec_t,3)
        )


        
        .def_static("from_ticks",&time_spec_t::from_ticks,       
            py::arg("ticks"),
            py::arg("tick_rate"),
            D(time_spec_t,from_ticks)
        )


        
        .def("get_tick_count",&time_spec_t::get_tick_count,       
            py::arg("tick_rate"),
            D(time_spec_t,get_tick_count)
        )


        
        .def("to_ticks",&time_spec_t::to_ticks,       
            py::arg("tick_rate"),
            D(time_spec_t,to_ticks)
        )


        
        .def("get_real_secs",&time_spec_t::get_real_secs,       
            D(time_spec_t,get_real_secs)
        )


        
        .def("get_full_secs",&time_spec_t::get_full_secs,       
            D(time_spec_t,get_full_secs)
        )


        
        .def("get_frac_secs",&time_spec_t::get_frac_secs,       
            D(time_spec_t,get_frac_secs)
        )

        ;




}








