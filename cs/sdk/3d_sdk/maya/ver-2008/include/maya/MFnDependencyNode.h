
#ifndef _MFnDependencyNode
#define _MFnDependencyNode
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MFnDependencyNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnDependencyNode)
//
//  MFnDependencyNode allows the creation and manipulation of dependency
//  graph nodes.  Traversal of the dependency graph is possible using the
//  getConnections method.
//
//  This function set does not support creation or removal of connections.  
//  MDGModifier should be used for that purpose.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MTypeId.h>
#include <maya/MString.h>

// *****************************************************************************

// DECLARATIONS

class MPlugArray;
class MPlug;
class MTypeId;
class MPxNode;
class MObjectArray;

// *****************************************************************************

// CLASS DECLARATION (MFnDependencyNode)

/// Dependency node function set. (OpenMaya) (OpenMaya.py)
/**
 MFnNumericData allows the manipulation of nodes in the dependency graph
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnDependencyNode : public MFnBase 
{

	declareMFn(MFnDependencyNode, MFnBase);

public:
    ///
	enum MAttrClass {
        ///
		kGlobalDynamicAttr = 1,
        ///
		kLocalDynamicAttr,
		//
		kNormalAttr,
		//
		kInvalidAttr
	};
		
    ///
    MObject         create( const MTypeId &typeId,
								MStatus* ReturnStatus = NULL );
    ///
    MObject         create( const MTypeId &typeId,
								const MString& name,
								MStatus* ReturnStatus = NULL );

    ///
    MObject         create( const MString &type,
								MStatus* ReturnStatus = NULL );
    ///
    MObject         create( const MString &type,
								const MString& name,
								MStatus* ReturnStatus = NULL );
	
	///
	MTypeId         typeId( MStatus* ReturnStatus = NULL ) const;
	///
	MString         typeName( MStatus* ReturnStatus = NULL ) const;
	///
	MString			name( MStatus * ReturnStatus = NULL ) const;
	///
	MString			setName( const MString &name,
							 MStatus * ReturnStatus = NULL );
    ///
	MStatus			getConnections( MPlugArray& array ) const;
    ///
	unsigned int		attributeCount( MStatus* ReturnStatus=NULL) const;
    ///
	MObject	        attribute(	unsigned int index,
								MStatus* ReturnStatus=NULL) const;
    ///
	MObject	        reorderedAttribute(	unsigned int index,
								MStatus* ReturnStatus=NULL) const;
    ///
	MObject	        attribute(	const MString& attrName,
								MStatus* ReturnStatus=NULL) const;
    ///
	MAttrClass		attributeClass(	const MObject& attr,
									MStatus* ReturnStatus=NULL) const;
	///
	MStatus			getAffectedAttributes ( const MObject& attr,
									MObjectArray& affectedAttributes ) const;
	///
	MStatus			getAffectedByAttributes ( const MObject& attr,
									MObjectArray& affectedByAttributes ) const;
     ///
	MPlug			findPlug(	const MObject & attr, bool wantNetworkedPlug,
								MStatus* ReturnStatus=NULL) const;
    ///
	MPlug			findPlug(	const MString & attrName, bool wantNetworkedPlug,
								MStatus* ReturnStatus=NULL) const;
   ///
	MPlug			findPlug(	const MObject & attr,
								MStatus* ReturnStatus=NULL) const;
    ///
	MPlug			findPlug(	const MString & attrName,
								MStatus* ReturnStatus=NULL) const;
    ///
	MStatus			addAttribute( const MObject & attr,
								MAttrClass type = kLocalDynamicAttr );
    ///
	MStatus			removeAttribute( const MObject & attr,
								MAttrClass type = kLocalDynamicAttr );
    ///
	MPxNode *  		userNode( MStatus* ReturnStatus=NULL ) const;
    ///
	bool			isFromReferencedFile(MStatus* ReturnStatus=NULL) const;
    ///
	bool			isShared(MStatus* ReturnStatus=NULL) const;
    ///
	bool			hasUniqueName(MStatus* ReturnStatus=NULL) const;
	///
	MString			parentNamespace(MStatus* ReturnStatus=NULL) const;
    ///
	bool			isLocked(MStatus* ReturnStatus=NULL) const;
	///
	MStatus			setLocked( bool locked );
	///
	static MString	classification( const MString & nodeTypeName );
	///
	bool			isNewAttribute( const MObject& attr,
								MStatus* ReturnStatus=NULL) const;
	///
	static unsigned int	allocateFlag(
						const MString pluginName, MStatus* ReturnStatus=NULL
					);
	///
	static MStatus	deallocateFlag(const MString pluginName, unsigned int flag);
	///
	static MStatus	deallocateAllFlags(const MString pluginName);
	///
	MStatus			setFlag(unsigned int flag, bool state);
	///
	bool			isFlagSet(unsigned int flag, MStatus* ReturnStatus=NULL) const;
	///
	bool			isDefaultNode(MStatus* ReturnStatus=NULL) const;

	///
	MStatus			setDoNotWrite ( bool flag );
	///
	bool			canBeWritten(MStatus* ReturnStatus=NULL) const;
	
	///
	bool			hasAttribute(const MString& name, MStatus* ReturnStatus=NULL) const;

	///
	MObject			getAliasAttr(bool force, MStatus* ReturnStatus=NULL);
	///
	bool			setAlias(const MString& alias,const MString& name, const MPlug& plug, bool add=true, 
					MStatus* ReturnStatus=NULL);
	///
	bool			findAlias(const MString& alias, MObject& attrObj, MStatus* ReturnStatus=NULL) const;
	///
	bool 			getAliasList(MStringArray& strArray, MStatus* ReturnStatus=NULL);
	///
	MString			plugsAlias(const MPlug& plug, MStatus* ReturnStatus=NULL);

BEGIN_NO_SCRIPT_SUPPORT:

	///	NO SCRIPT SUPPORT
 	declareMFnConstConstructor( MFnDependencyNode, MFnBase );
	///	NO SCRIPT SUPPORT
	bool			getPlugsAlias(const MPlug& plug, MString& aliasName, MStatus* ReturnStatus=NULL);
	
END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members

};
#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnDependencyNode */
