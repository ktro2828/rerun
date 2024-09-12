// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/datatypes/video_timestamp.fbs".

#pragma once

#include "../result.hpp"

#include <cstdint>
#include <memory>

namespace arrow {
    /// \private
    template <typename T>
    class NumericBuilder;

    class Array;
    class DataType;
    class UInt8Type;
    using UInt8Builder = NumericBuilder<UInt8Type>;
} // namespace arrow

namespace rerun::datatypes {
    /// **Datatype**: Specifies how to interpret the `video_time` field of a `datatypes::VideoTimestamp`.
    enum class VideoTimeMode : uint8_t {

        /// Presentation timestamp in nanoseconds since the beginning of the video.
        Nanoseconds = 1,
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::VideoTimeMode> {
        static constexpr const char Name[] = "rerun.datatypes.VideoTimeMode";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::datatypes::VideoTimeMode` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const datatypes::VideoTimeMode* instances, size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::UInt8Builder* builder, const datatypes::VideoTimeMode* elements,
            size_t num_elements
        );
    };
} // namespace rerun