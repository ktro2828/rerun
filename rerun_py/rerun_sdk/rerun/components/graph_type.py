# DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/python/mod.rs
# Based on "crates/store/re_types/definitions/rerun/components/graph_type.fbs".

# You can extend this class by creating a "GraphTypeExt" class in "graph_type_ext.py".

from __future__ import annotations

from typing import Literal, Sequence, Union

import pyarrow as pa

from .._baseclasses import (
    BaseBatch,
    ComponentBatchMixin,
)

__all__ = ["GraphType", "GraphTypeArrayLike", "GraphTypeBatch", "GraphTypeLike"]


from enum import Enum


class GraphType(Enum):
    """**Component**: Specifies if a graph has directed or undirected edges."""

    Undirected = 1
    """The graph has undirected edges."""

    Directed = 2
    """The graph has directed edges."""

    @classmethod
    def auto(cls, val: str | int | GraphType) -> GraphType:
        """Best-effort converter, including a case-insensitive string matcher."""
        if isinstance(val, GraphType):
            return val
        if isinstance(val, int):
            return cls(val)
        try:
            return cls[val]
        except KeyError:
            val_lower = val.lower()
            for variant in cls:
                if variant.name.lower() == val_lower:
                    return variant
        raise ValueError(f"Cannot convert {val} to {cls.__name__}")

    def __str__(self) -> str:
        """Returns the variant name."""
        return self.name


GraphTypeLike = Union[GraphType, Literal["Directed", "Undirected", "directed", "undirected"], int]
GraphTypeArrayLike = Union[GraphTypeLike, Sequence[GraphTypeLike]]


class GraphTypeBatch(BaseBatch[GraphTypeArrayLike], ComponentBatchMixin):
    _ARROW_DATATYPE = pa.uint8()
    _COMPONENT_NAME: str = "rerun.components.GraphType"

    @staticmethod
    def _native_to_pa_array(data: GraphTypeArrayLike, data_type: pa.DataType) -> pa.Array:
        if isinstance(data, (GraphType, int, str)):
            data = [data]

        pa_data = [GraphType.auto(v).value if v is not None else None for v in data]  # type: ignore[redundant-expr]

        return pa.array(pa_data, type=data_type)
