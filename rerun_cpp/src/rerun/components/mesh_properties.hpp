// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/mesh_properties.fbs".

#pragma once

#include "../data_cell.hpp"
#include "../datatypes/mesh_properties.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

namespace arrow {
    class DataType;
    class MemoryPool;
    class StructBuilder;
} // namespace arrow

namespace rerun {
    namespace components {
        struct MeshProperties {
            rerun::datatypes::MeshProperties props;

            /// Name of the component, used for serialization.
            static const char NAME[];

          public:
            // Extensions to generated type defined in 'mesh_properties_ext.cpp'

            static MeshProperties from_triangle_indices(std::vector<uint32_t> indices) {
                return MeshProperties(indices);
            }

          public:
            MeshProperties() = default;

            MeshProperties(rerun::datatypes::MeshProperties _props) : props(std::move(_props)) {}

            MeshProperties& operator=(rerun::datatypes::MeshProperties _props) {
                props = std::move(_props);
                return *this;
            }

            MeshProperties(std::optional<std::vector<uint32_t>> arg) : props(std::move(arg)) {}

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static Result<std::shared_ptr<arrow::StructBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static Error fill_arrow_array_builder(
                arrow::StructBuilder* builder, const MeshProperties* elements, size_t num_elements
            );

            /// Creates a Rerun DataCell from an array of MeshProperties components.
            static Result<rerun::DataCell> to_data_cell(
                const MeshProperties* instances, size_t num_instances
            );
        };
    } // namespace components
} // namespace rerun