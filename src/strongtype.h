// Copyright (c) 2025-2026 Adrien Sporrer
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

template <typename Type, typename Tag>
class StrongType {
public:
    using UnderlyingType = Type;

    constexpr explicit StrongType(const Type& value) : m_value(value) {}

    constexpr const Type& value() const { return m_value; }

    constexpr bool operator==(const StrongType& other) const { return m_value == other.m_value; }

private:
    constexpr StrongType() = default;

    const Type m_value;
};

#include <QHashFunctions>

template <typename Type, typename Tag>
size_t qHash(const StrongType<Type, Tag>& key, const size_t seed = 0) {
    return qHash(key.value(), seed);
}

#include <QDebug>

template <typename Type, typename Tag>
QDebug operator<<(QDebug debug, const StrongType<Type, Tag>& key) {
    return debug << key.value();
}

#define DECLARE_STRONG_TYPE(Name, Type) using Name = StrongType<Type, struct Name##Tag>;