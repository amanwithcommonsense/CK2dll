#pragma once

#define NOMINMAX

#include <windows.h>
#include <cstdint>
#include <cstddef>
#include <fstream>
#include <utility>
#include <unordered_map>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include <cstring>
#include <filesystem>
#include <boost/utility/string_view.hpp>
#include "../include/injector/hooking.hpp"
#include "../include/injector/calling.hpp"
#include "../include/injector/assembly.hpp"

#define VALIDATE_SIZE(type,size) static_assert(sizeof(type)==size, "Type size error.");

struct IncompleteClass
{
    template <typename T, std::uintptr_t offset>
    T *field()
    {
        return (T *)(reinterpret_cast<std::uintptr_t>(this) + offset);
    }

    template <typename T, std::uintptr_t offset>
    T get_field()
    {
        return *(T *)(reinterpret_cast<std::uintptr_t>(this) + offset);
    }
};

#define ESCAPE_SEQ_1 0x10
#define ESCAPE_SEQ_2 0x11
#define ESCAPE_SEQ_3 0x12
#define ESCAPE_SEQ_4 0x13

#define LOW_SHIFT 0x0F
#define HIGH_SHIFT 0x9

#define SHIFT_2 LOW_SHIFT
#define SHIFT_3 0x900
#define SHIFT_4 0x8F1

#define NO_FONT 0x98F
#define NOT_DEF 0x2026

#define CK2ERROR1 0x10000

enum CK2Version {
	UNKNOWN = 0,
	v2_7_X = 27,
	v2_8_X = 28,
	v3_0_X = 30
};

enum NickNameOrder {
	DISABLE, // original
	NICKNAME_FIRSTNAME_TITLE,
	FIRSTNAME_NICKNAME_TITLE,
	TITLE_NICKNAME_FIRSTNAME
};

typedef struct _runoption {
	// プログラムバージョン
	CK2Version version;

	// 日付の表記変更を有効にするか
	boolean dateFormat;
	// ニックネームの種別
	// 0 : 無効
	// 1 : [FirstName] [Nickname] [Title]
	// 2 : [Nickname] [FirstName] [Title]
	NickNameOrder nickNameOrder;

} RunOptions;

namespace Misc
{
	CK2Version getVersion();
	std::string versionString(CK2Version version);
	errno_t init(CK2Version version);

	void getOptionsByINI(RunOptions *option);
}

namespace MapView
{
	errno_t init(CK2Version version);
}

namespace MapJustify
{
	errno_t init(CK2Version version);
}

namespace Font
{
	errno_t init(CK2Version version);
}

namespace DecorativeLetterEndDialog
{
	errno_t init(CK2Version version);
}

namespace DecorativeLetterDialog
{
	errno_t init(CK2Version version);
}

namespace DecorativeLetterInheritDialog
{
	errno_t init(CK2Version version);
}

namespace ButtonAndTooltip
{
	errno_t init(CK2Version version);
}

namespace MainText
{
	errno_t init(CK2Version version);
}

namespace NickNameFix
{
	errno_t init(RunOptions *options);
}

namespace NoDynastyId
{
	errno_t init(CK2Version version);
}

namespace IME
{
	errno_t init(CK2Version version);
}

namespace Input
{
	errno_t init(CK2Version version);
}

namespace MapAdj
{
	errno_t init(CK2Version version);
}

namespace MainTextLineBreak
{
	errno_t init(CK2Version version);
}

namespace MapAdj3
{
	errno_t init(CK2Version version);
}

namespace Unk3
{
	errno_t init(CK2Version version);
}

namespace Unk4
{
	errno_t init(CK2Version version);
}

namespace MapAdj2
{
	errno_t init(CK2Version version);
}

namespace Issue33
{
	errno_t init(CK2Version version);
}

namespace Issue32
{
	errno_t init(CK2Version version);
}

namespace DateFormat
{
	errno_t init(RunOptions *options);
}

union T {
	char text[0x10];
	char* p;
};

typedef struct {
	union T t;
	int len;
	int len2;
} V;