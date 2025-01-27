#pragma once

#include "RE/Bethesda/BSGraphics.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiProperty.h"

namespace RE
{
	class BSCombinedTriShape;
	class BSGeometrySegmentData;
	class BSMergeInstancedTriShape;
	class BSMultiIndexTriShape;

	namespace BSGraphics
	{
		struct IndexBuffer;
	}

	namespace BSSkin
	{
		class Instance;
	}

	class __declspec(novtable) BSGeometry :
		public NiAVObject  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGeometry };
		static constexpr auto VTABLE{ VTABLE::BSGeometry };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSGeometry };

		BSGeometry();
		virtual ~BSGeometry();  // NOLINT(modernize-use-override) 00

		// add
		virtual void UpdatePropertyControllers(NiUpdateData& a_data);      // 3A
		virtual BSGeometrySegmentData* GetSegmentData();                   // 3B
		virtual void SetSegmentData(BSGeometrySegmentData* a_data);        // 3C
		virtual BSGraphics::IndexBuffer* GetCustomIndexBuffer();           // 3D
		virtual BSCombinedTriShape* IsBSCombinedTriShape();                // 3E
		virtual BSMergeInstancedTriShape* IsBSMergeInstancedTriShape();    // 3F
		virtual BSMultiIndexTriShape* IsMultiIndexTriShape();              // 40
		virtual std::uint32_t GetRenderableTris(std::uint32_t a_LODMode);  // 40

		// members
		NiBound modelBound;                        // 120
		NiPointer<NiProperty> properties[2];       // 130
		NiPointer<BSSkin::Instance> skinInstance;  // 140
		void* rendererData;                        // 148
		BSGraphics::VertexDesc vertexDesc;         // 150
		std::uint8_t type;                         // 158
		bool registered;                           // 159
	};
	static_assert(sizeof(BSGeometry) == 0x160);
}
