/* ----------------------------------------------------------------------
* I-SIMPA (http://i-simpa.ifsttar.fr). This file is part of I-SIMPA.
*
* I-SIMPA is a GUI for 3D numerical sound propagation modelling dedicated
* to scientific acoustic simulations.
* Copyright (C) 2007-2014 - IFSTTAR - Judicael Picaut, Nicolas Fortin
*
* I-SIMPA is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
* 
* I-SIMPA is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA or 
* see <http://ww.gnu.org/licenses/>
*
* For more information, please consult: <http://i-simpa.ifsttar.fr> or 
* send an email to i-simpa@ifsttar.fr
*
* To contact Ifsttar, write to Ifsttar, 14-20 Boulevard Newton
* Cite Descartes, Champs sur Marne F-77447 Marne la Vallee Cedex 2 FRANCE
* or write to scientific.computing@ifsttar.fr
* ----------------------------------------------------------------------*/

#include "first_header_include.hpp"

#include "data_manager/element.h"

/** \file e_scene_recepteurss_recepteurcoupe_rendu.h
   \brief Element correspondant à la configuration de rendu 3D d'un récepteur de surface
*/

/**
   \brief Element correspondant à la configuration de rendu 3D d'un récepteur de surface
   @see E_Scene_Recepteurss_Recepteur
*/
class E_Scene_Recepteurss_RecepteurCoupe_Rendu: public Element
{
public:
	E_Scene_Recepteurss_RecepteurCoupe_Rendu( wxXmlNode* noeudCourant ,  Element* parent)
		:Element(parent,"Display",Element::ELEMENT_TYPE_SCENE_RECEPTEURSS_RECEPTEURCOUPE_RENDU,noeudCourant)
	{
		SetIcon(GRAPH_STATE_ALL,GRAPH_EL_3D_DISPLAY);
		_("Display");
	}

	E_Scene_Recepteurss_RecepteurCoupe_Rendu( Element* parent)
		:Element(parent,"Display",Element::ELEMENT_TYPE_SCENE_RECEPTEURSS_RECEPTEURCOUPE_RENDU)
	{
		SetIcon(GRAPH_STATE_ALL,GRAPH_EL_3D_DISPLAY);
		this->AppendPropertyBool("showplane","Show the grid",true);
		this->AppendPropertyBool("showlabels","Show vertices name",true);
		this->AppendPropertyColor("planecolor","Cut color",241,243,175);
		_("Show the grid");
		_("Show vertices name");
		_("Cut color");
	}

	
	wxXmlNode* SaveXMLDoc(wxXmlNode* NoeudParent)
	{
		wxXmlNode* thisNode = Element::SaveXMLDoc(NoeudParent);
		thisNode->SetName("rendu"); // Nom de la balise xml ( pas d'espace autorise )
		return thisNode;
	}
};
