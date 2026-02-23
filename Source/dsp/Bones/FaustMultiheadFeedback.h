/* ------------------------------------------------------------
name: "multiheadFeedback"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -a minimal.cpp -lang cpp -i -fpga-mem-th 4 -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/******************* BEGIN minimal.cpp ****************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include <iostream>

/************************** BEGIN PrintUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *********************************************************************/

#ifndef FAUST_PRINTUI_H
#define FAUST_PRINTUI_H

#include <vector>
#include <string>
#include <iostream>

/************************** BEGIN UI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __UI_H__
#define __UI_H__

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***************************************************************************/

#ifndef __export__
#define __export__

// Version as a global string
#define FAUSTVERSION "2.83.1"

// Version as separated [major,minor,patch] values
#define FAUSTMAJORVERSION 2
#define FAUSTMINORVERSION 83
#define FAUSTPATCHVERSION 1

// Use FAUST_API for code that is part of the external API but is also compiled in faust and libfaust
// Use LIBFAUST_API for code that is compiled in faust and libfaust

#ifdef _WIN32
    #pragma warning (disable: 4251)
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #elif FAUST_LIB
        #define FAUST_API __declspec(dllexport)
        #define LIBFAUST_API __declspec(dllexport)
    #else
        #define FAUST_API
        #define LIBFAUST_API 
    #endif
#else
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #else
        #define FAUST_API __attribute__((visibility("default")))
        #define LIBFAUST_API __attribute__((visibility("default")))
    #endif
#endif

#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
struct FAUST_API UIReal {
    
    UIReal() {}
    virtual ~UIReal() {}
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // -- active widgets
    
    virtual void addButton(const char* label, REAL* zone) = 0;
    virtual void addCheckButton(const char* label, REAL* zone) = 0;
    virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
    
    // -- metadata declarations
    
    virtual void declare(REAL* /*zone*/, const char* /*key*/, const char* /*val*/) {}

    // To be used by LLVM client
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
};

struct FAUST_API UI : public UIReal<FAUSTFLOAT> {
    UI() {}
    virtual ~UI() {}
#ifdef DAISY_NO_RTTI
    virtual bool isSoundUI() const { return false; }
    virtual bool isMidiInterface() const { return false; }
#endif
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN PathBuilder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __PathBuilder__
#define __PathBuilder__

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>


/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class FAUST_API PathBuilder {

    protected:
    
        std::vector<std::string> fControlsLevel;
        std::vector<std::string> fFullPaths;
        std::map<std::string, std::string> fFull2Short;  // filled by computeShortNames()
    
        /**
         * @brief check if a character is acceptable for an ID
         *
         * @param c
         * @return true is the character is acceptable for an ID
         */
        bool isIDChar(char c) const
        {
            return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
        }
    
        /**
         * @brief remove all "/0x00" parts
         *
         * @param src
         * @return modified string
         */
        std::string remove0x00(const std::string& src_aux) const
        {
            std::string src = src_aux;
            std::string from = "/0x00";
            std::string to = "";
            size_t pos = std::string::npos;
            while ((pos = src.find(from)) && (pos != std::string::npos)) {
                src = src.replace(pos, from.length(), to);
            }
            return src;
        }
    
        /**
         * @brief replace all non ID char with '_' (one '_' may replace several non ID char)
         *
         * @param src
         * @return modified string
         */
        std::string str2ID(const std::string& src) const
        {
            std::string dst;
            bool need_underscore = false;
            for (char c : src) {
                if (isIDChar(c) || (c == '/')) {
                    if (need_underscore) {
                        dst.push_back('_');
                        need_underscore = false;
                    }
                    dst.push_back(c);
                } else {
                    need_underscore = true;
                }
            }
            return dst;
        }
    
        /**
         * @brief Keep only the last n slash-parts
         *
         * @param src
         * @param n : 1 indicates the last slash-part
         * @return modified string
         */
        std::string cut(const std::string& src, int n) const
        {
            std::string rdst;
            for (int i = int(src.length())-1; i >= 0; i--) {
                char c = src[i];
                if (c != '/') {
                    rdst.push_back(c);
                } else if (n == 1) {
                    std::string dst;
                    for (int j = int(rdst.length())-1; j >= 0; j--) {
                        dst.push_back(rdst[j]);
                    }
                    return dst;
                } else {
                    n--;
                    rdst.push_back(c);
                }
            }
            return src;
        }
    
        void addFullPath(const std::string& label) { fFullPaths.push_back(buildPath(label)); }
    
        /**
         * @brief Compute the mapping between full path and short names
         */
        void computeShortNames()
        {
            std::vector<std::string>           uniquePaths;  // all full paths transformed but made unique with a prefix
            std::map<std::string, std::string> unique2full;  // all full paths transformed but made unique with a prefix
            char num_buffer[16];
            int pnum = 0;
            
            for (const auto& s : fFullPaths) {
                // Using snprintf since Teensy does not have the std::to_string function
                snprintf(num_buffer, 16, "%d", pnum++);
                std::string u = "/P" + std::string(num_buffer) + str2ID(remove0x00(s));
                uniquePaths.push_back(u);
                unique2full[u] = s;  // remember the full path associated to a unique path
            }
        
            std::map<std::string, int> uniquePath2level;                // map path to level
            for (const auto& s : uniquePaths) uniquePath2level[s] = 1;   // we init all levels to 1
            bool have_collisions = true;
        
            while (have_collisions) {
                // compute collision list
                std::set<std::string>              collisionSet;
                std::map<std::string, std::string> short2full;
                have_collisions = false;
                for (const auto& it : uniquePath2level) {
                    std::string u = it.first;
                    int n = it.second;
                    std::string shortName = cut(u, n);
                    auto p = short2full.find(shortName);
                    if (p == short2full.end()) {
                        // no collision
                        short2full[shortName] = u;
                    } else {
                        // we have a collision, add the two paths to the collision set
                        have_collisions = true;
                        collisionSet.insert(u);
                        collisionSet.insert(p->second);
                    }
                }
                for (const auto& s : collisionSet) uniquePath2level[s]++;  // increase level of colliding path
            }
        
            for (const auto& it : uniquePath2level) {
                std::string u = it.first;
                int n = it.second;
                std::string shortName = replaceCharList(cut(u, n), {'/'}, '_');
                fFull2Short[unique2full[u]] = shortName;
            }
        }
    
        std::string replaceCharList(const std::string& str, const std::vector<char>& ch1, char ch2)
        {
            auto beg = ch1.begin();
            auto end = ch1.end();
            std::string res = str;
            for (size_t i = 0; i < str.length(); ++i) {
                if (std::find(beg, end, str[i]) != end) res[i] = ch2;
            }
            return res;
        }
     
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        // Return true for the first level of groups
        bool pushLabel(const std::string& label_aux)
        {
            std::string label = replaceCharList(label_aux, {'/'}, '_');
            fControlsLevel.push_back(label); return fControlsLevel.size() == 1;
        }
    
        // Return true for the last level of groups
        bool popLabel() { fControlsLevel.pop_back(); return fControlsLevel.size() == 0; }
    
        // Return a complete path built from a label
        std::string buildPath(const std::string& label_aux)
        {
            std::string label = replaceCharList(label_aux, {'/'}, '_');
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res = res + fControlsLevel[i] + "/";
            }
            res += label;
            return replaceCharList(res, {' ', '#', '*', ',', '?', '[', ']', '{', '}', '(', ')'}, '_');
        }
    
        // Assuming shortnames have been built, return the shortname from a label
        std::string buildShortname(const std::string& label)
        {
            return (hasShortname()) ? fFull2Short[buildPath(label)] : "";
        }
    
        bool hasShortname() { return fFull2Short.size() > 0; }
    
};

#endif  // __PathBuilder__
/**************************  END  PathBuilder.h **************************/

/*******************************************************************************
 * PrintUI : Faust User Interface
 * This class print arguments given to calls to UI methods and build complete path for labels.
 ******************************************************************************/

class PrintUI : public PathBuilder, public UI {

    public:

        PrintUI() {}
        virtual ~PrintUI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label)
        {
            pushLabel(label);
            std::cout << "openTabBox label : [" << label << "]" << std::endl;
        }
        virtual void openHorizontalBox(const char* label)
        {
            pushLabel(label);
            std::cout << "openHorizontalBox label : [" << label << "]" << std::endl;
        }
        virtual void openVerticalBox(const char* label)
        {
            pushLabel(label);
            std::cout << "openVerticalBox label : [" << label << "]" << std::endl;
        }
        virtual void closeBox()
        {
            popLabel();
            std::cout << "closeBox" << std::endl;
        }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            std::cout << "addButton label : [" << buildPath(label) << "]" << std::endl;
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            std::cout << "addCheckButton label : [" << buildPath(label) << "]" << std::endl;
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            std::cout << "addVerticalSlider label : [" << buildPath(label) << " init : " << init << " min : " << min << " max : " << max << " step : " << step << "]" << std::endl;
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            std::cout << "addHorizontalSlider label : [" << buildPath(label) << " init : " << init << " min : " << min << " max : " << max << " step : " << step << "]" << std::endl;
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            std::cout << "addNumEntry label : [" << buildPath(label) << " init : " << init << " min : " << min << " max : " << max << " step : " << step << "]" << std::endl;
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            std::cout << "addHorizontalBargraph label : [" << buildPath(label) << " min : " << min << " max : " << max << "]" << std::endl;
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            std::cout << "addVerticalBargraph label : [" << buildPath(label) << " min : " << min << " max : " << max << "]" << std::endl;
        }
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename,  Soundfile** sf_zone)
        {
            std::cout << "addSoundfile label : [" << buildPath(label) << " filename :" << filename << "]" << std::endl;
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            std::cout << "declare key : [" << key << " val : " << val << "]" << std::endl;
        }
    
};

#endif // FAUST_PRINTUI_H
/**************************  END  PrintUI.h **************************/
/************************** BEGIN MapUI.h ******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>


/*******************************************************************************
 * MapUI : Faust User Interface.
 *
 * This class creates:
 * - a map of 'labels' and zones for each UI item.
 * - a map of unique 'shortname' (built so that they never collide) and zones for each UI item
 * - a map of complete hierarchical 'paths' and zones for each UI item
 *
 * Simple 'labels', 'shortname' and complete 'paths' (to fully discriminate between possible same
 * 'labels' at different location in the UI hierachy) can be used to access a given parameter.
 ******************************************************************************/

class FAUST_API MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
        // Shortname zone map
        std::map<std::string, FAUSTFLOAT*> fShortnameZoneMap;
    
        // Full path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        void addZoneLabel(const std::string& label, FAUSTFLOAT* zone)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            fPathZoneMap[path] = zone;
            fLabelZoneMap[label] = zone;
        }
    
    public:
        
        MapUI() {}
        virtual ~MapUI() {}
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& it : fFullPaths) {
                    fShortnameZoneMap[fFull2Short[it]] = fPathZoneMap[it];
                }
            }
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
    
        //-------------------------------------------------------------------------------
        // Public API
        //-------------------------------------------------------------------------------
    
        /**
         * Set the param value.
         *
         * @param str - the UI parameter label/shortname/path
         * @param value - the UI parameter value
         *
         */
        void setParamValue(const std::string& str, FAUSTFLOAT value)
        {
            const auto fPathZoneMapIter = fPathZoneMap.find(str);
            if (fPathZoneMapIter != fPathZoneMap.end()) {
                *fPathZoneMapIter->second = value;
                return;
            }
            
            const auto fShortnameZoneMapIter = fShortnameZoneMap.find(str);
            if (fShortnameZoneMapIter != fShortnameZoneMap.end()) {
                *fShortnameZoneMapIter->second = value;
                return;
            }
            
            const auto fLabelZoneMapIter = fLabelZoneMap.find(str);
            if (fLabelZoneMapIter != fLabelZoneMap.end()) {
                *fLabelZoneMapIter->second = value;
                return;
            }
            
            fprintf(stderr, "ERROR : setParamValue '%s' not found\n", str.c_str());
        }
        
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const std::string& str) const
        {
            const auto fPathZoneMapIter = fPathZoneMap.find(str);
            if (fPathZoneMapIter != fPathZoneMap.end()) {
                return *fPathZoneMapIter->second;
            }
            
            const auto fShortnameZoneMapIter = fShortnameZoneMap.find(str);
            if (fShortnameZoneMapIter != fShortnameZoneMap.end()) {
                return *fShortnameZoneMapIter->second;
            }
            
            const auto fLabelZoneMapIter = fLabelZoneMap.find(str);
            if (fLabelZoneMapIter != fLabelZoneMap.end()) {
                return *fLabelZoneMapIter->second;
            }
            
            fprintf(stderr, "ERROR : getParamValue '%s' not found\n", str.c_str());
            return 0;
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getFullpathMap() { return fPathZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getShortnameMap() { return fShortnameZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getLabelMap() { return fLabelZoneMap; }
            
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() const { return int(fPathZoneMap.size()); }
        
        /**
         * Return the param path.
         *
         * @param index - the UI parameter index
         *
         * @return the param path
         */
        std::string getParamAddress(int index) const
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return "";
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamAddress1(int index) const
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param shortname.
         *
         * @param index - the UI parameter index
         *
         * @return the param shortname
         */
        std::string getParamShortname(int index) const
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return "";
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamShortname1(int index) const
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param label.
         *
         * @param index - the UI parameter index
         *
         * @return the param label
         */
        std::string getParamLabel(int index) const
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return "";
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamLabel1(int index) const
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param path.
         *
         * @param zone - the UI parameter memory zone
         *
         * @return the param path
         */
        std::string getParamAddress(FAUSTFLOAT* zone) const
        {
            for (const auto& it : fPathZoneMap) {
                if (it.second == zone) return it.first;
            }
            return "";
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter label/shortname/path
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(const std::string& str) const
        {
            const auto fPathZoneMapIter = fPathZoneMap.find(str);
            if (fPathZoneMapIter != fPathZoneMap.end()) {
                return fPathZoneMapIter->second;
            }
            
            const auto fShortnameZoneMapIter = fShortnameZoneMap.find(str);
            if (fShortnameZoneMapIter != fShortnameZoneMap.end()) {
                return fShortnameZoneMapIter->second;
            }
            
            const auto fLabelZoneMapIter = fLabelZoneMap.find(str);
            if (fLabelZoneMapIter != fLabelZoneMap.end()) {
                return fLabelZoneMapIter->second;
            }

            return nullptr;
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter index
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(int index) const 
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->second;
            }
        }
    
        static bool endsWith(const std::string& str, const std::string& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
    
};

#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
#ifdef LAYOUT_UI
/************************** BEGIN LayoutUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_LAYOUTUI_H
#define FAUST_LAYOUTUI_H

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <iostream>
#include <ostream>

/************************** BEGIN DecoratorUI.h **************************
 FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class FAUST_API GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}

#ifdef DAISY_NO_RTTI
        virtual bool isSoundUI() const override { return true; }
#endif
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class FAUST_API DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

// Defined here to simplify header #include inclusion 
class FAUST_API SoundUIInterface : public GenericUI {};

#endif
/**************************  END  DecoratorUI.h **************************/
/************************** BEGIN MetaDataUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef MetaData_UI_H
#define MetaData_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <map>
#include <set>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h> // We use the lighter fprintf code

/************************** BEGIN SimpleParser.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h> // We use the lighter fprintf code
#include <ctype.h>
#include <assert.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string varname;
    std::string shortname;
    std::string address;
    std::string url;
    int index;
    double init;
    double fmin;
    double fmax;
    double step;
    std::vector<std::pair<std::string, std::string> > meta;
    
    itemInfo():index(0), init(0.), fmin(0.), fmax(0.), step(0.)
    {}
};

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    fprintf(stderr, "Parse error : %s here : %s\n", errmsg, p);
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] or [s]d[.dddd][E|e][s][dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = 1.0;     // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    double expsign = 1.0;  // sign of the E|e part
    double expcoef = 0.0;  // multiplication factor of E|e part
    
    bool valid = false;    // true if the number contains at least one digit
    
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    
    // Sign
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    
    // Integral part
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    
    // Possible decimal part
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    
    // Possible E|e part
    if (parseChar(p, 'E') || parseChar(p, 'e')) {
        if (parseChar(p, '+')) {
            expsign = 1.0;
        } else if (parseChar(p, '-')) {
            expsign = -1.0;
        }
        while (isdigit(*p)) {
            expcoef = expcoef*10 + (*p - '0');
            p++;
        }
    }
    
    if (valid)  {
        x = (sign*(ipart + dpart/dcoef)) * std::pow(10.0, expcoef*expsign);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    // single quoted
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { fprintf(stderr, "parseMenuList2 : (%s) is not a valid list !\n", p); }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, double& dbl, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    const char* saved = p; // to restore position if we fail
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items) || parseDouble(p, dbl));
        }
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo>& uiItems, int& numItems)
{
    const char* saved = p; // to restore position if we fail
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        double dbl = 0;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo item;
                        item.type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].label = value;
                    }
                }
                
                else if (label == "varname") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].varname = value;
                    }
                }
                
                else if (label == "shortname") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].shortname = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].address = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].url = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].index = int(dbl);
                    }
                }
                
                else if (label == "meta") {
                    if (!parseItemMetaData(p, uiItems[numItems].meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].init = dbl;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmin = dbl;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmax = dbl;
                    }
                }
                
                else if (label == "step") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].step = dbl;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do {
                            if (!parseUI(p, uiItems, numItems)) {
                                p = saved;
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo item;
                            item.type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
            
                } else {
                    fprintf(stderr, "Parse error unknown : %s \n", label.c_str());
                    assert(false);
                }
            } else {
                p = saved;
                return false;
            }
            
        } while (tryChar(p, ','));
    
        return parseChar(p, '}');
    } else {
        return true; // "items": [] is valid
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p,
                      std::map<std::string, std::pair<std::string, double> >& metaDatas0,
                      std::map<std::string, std::string>& metaDatas1,
                      std::map<std::string, std::vector<std::string> >& metaDatas2,
                      std::vector<itemInfo>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        double dbl = 0;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, dbl, metaDatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metaDatas2[key] = items;
                    items.clear();
                } else if (value != "") {
                    metaDatas0[key].first = value;
                } else {
                    metaDatas0[key].second = dbl;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H
/**************************  END  SimpleParser.h **************************/

static bool startWith(const std::string& str, const std::string& prefix)
{
    return (str.substr(0, prefix.size()) == prefix);
}

/**
 * Convert a dB value into a scale between 0 and 1 (following IEC standard ?)
 */
static FAUSTFLOAT dB2Scale(FAUSTFLOAT dB)
{
    FAUSTFLOAT scale = FAUSTFLOAT(1.0);
    
    /*if (dB < -70.0f)
     scale = 0.0f;
     else*/
    if (dB < FAUSTFLOAT(-60.0))
        scale = (dB + FAUSTFLOAT(70.0)) * FAUSTFLOAT(0.0025);
    else if (dB < FAUSTFLOAT(-50.0))
        scale = (dB + FAUSTFLOAT(60.0)) * FAUSTFLOAT(0.005) + FAUSTFLOAT(0.025);
    else if (dB < FAUSTFLOAT(-40.0))
        scale = (dB + FAUSTFLOAT(50.0)) * FAUSTFLOAT(0.0075) + FAUSTFLOAT(0.075);
    else if (dB < FAUSTFLOAT(-30.0))
        scale = (dB + FAUSTFLOAT(40.0)) * FAUSTFLOAT(0.015) + FAUSTFLOAT(0.15);
    else if (dB < FAUSTFLOAT(-20.0))
        scale = (dB + FAUSTFLOAT(30.0)) * FAUSTFLOAT(0.02) + FAUSTFLOAT(0.3);
    else if (dB < FAUSTFLOAT(-0.001) || dB > FAUSTFLOAT(0.001))  /* if (dB < 0.0) */
        scale = (dB + FAUSTFLOAT(20.0)) * FAUSTFLOAT(0.025) + FAUSTFLOAT(0.5);
    
    return scale;
}

/*******************************************************************************
 * MetaDataUI : Common class for MetaData handling
 ******************************************************************************/

//============================= BEGIN GROUP LABEL METADATA===========================
// Unlike widget's label, metadata inside group's label are not extracted directly by
// the Faust compiler. Therefore they must be extracted within the architecture file
//-----------------------------------------------------------------------------------

class MetaDataUI {
    
    protected:
        
        std::string                         fGroupTooltip;
        std::map<FAUSTFLOAT*, FAUSTFLOAT>   fGuiSize;            // map widget zone with widget size coef
        std::map<FAUSTFLOAT*, std::string>  fTooltip;            // map widget zone with tooltip strings
        std::map<FAUSTFLOAT*, std::string>  fUnit;               // map widget zone to unit string (i.e. "dB")
        std::map<FAUSTFLOAT*, std::string>  fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
        std::map<FAUSTFLOAT*, std::string>  fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
        std::set<FAUSTFLOAT*>               fKnobSet;            // set of widget zone to be knobs
        std::set<FAUSTFLOAT*>               fLedSet;             // set of widget zone to be LEDs
        std::set<FAUSTFLOAT*>               fNumSet;             // set of widget zone to be numerical bargraphs
        std::set<FAUSTFLOAT*>               fLogSet;             // set of widget zone having a log UI scale
        std::set<FAUSTFLOAT*>               fExpSet;             // set of widget zone having an exp UI scale
        std::set<FAUSTFLOAT*>               fHiddenSet;          // set of hidden widget zone
        
        void clearMetadata()
        {
            fGuiSize.clear();
            fTooltip.clear();
            fUnit.clear();
            fRadioDescription.clear();
            fMenuDescription.clear();
            fKnobSet.clear();
            fLedSet.clear();
            fNumSet.clear();
            fLogSet.clear();
            fExpSet.clear();
            fHiddenSet.clear();
            fGroupTooltip = "";
        }
        
        /**
         * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
         * (but not those in the middle of the string)
         */
        static std::string rmWhiteSpaces(const std::string& s)
        {
            size_t i = s.find_first_not_of(" \t");
            size_t j = s.find_last_not_of(" \t");
            if ((i != std::string::npos) && (j != std::string::npos)) {
                return s.substr(i, 1+j-i);
            } else {
                return "";
            }
        }
        
        /**
         * Format tooltip string by replacing some white spaces by
         * return characters so that line width doesn't exceed n.
         * Limitation : long words exceeding n are not cut.
         */
        std::string formatTooltip(int n, const std::string& tt)
        {
            std::string ss = tt;  // ss string we are going to format
            int lws = 0;          // last white space encountered
            int lri = 0;          // last return inserted
            for (int i = 0; i < (int)tt.size(); i++) {
                if (tt[i] == ' ') lws = i;
                if (((i-lri) >= n) && (lws > lri)) {
                    // insert return here
                    ss[lws] = '\n';
                    lri = lws;
                }
            }
            return ss;
        }
        
    public:
        
        virtual ~MetaDataUI()
        {}
        
        enum Scale {
            kLin,
            kLog,
            kExp
        };
        
        Scale getScale(FAUSTFLOAT* zone)
        {
            if (fLogSet.count(zone) > 0) return kLog;
            if (fExpSet.count(zone) > 0) return kExp;
            return kLin;
        }
        
        bool isKnob(FAUSTFLOAT* zone)
        {
            return fKnobSet.count(zone) > 0;
        }
        
        bool isRadio(FAUSTFLOAT* zone)
        {
            return fRadioDescription.count(zone) > 0;
        }
        
        bool isMenu(FAUSTFLOAT* zone)
        {
            return fMenuDescription.count(zone) > 0;
        }
        
        bool isLed(FAUSTFLOAT* zone)
        {
            return fLedSet.count(zone) > 0;
        }
        
        bool isNumerical(FAUSTFLOAT* zone)
        {
            return fNumSet.count(zone) > 0;
        }
        
        bool isHidden(FAUSTFLOAT* zone)
        {
            return fHiddenSet.count(zone) > 0;
        }
        
        /**
         * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata(unit=dB)
         */
        static void extractMetadata(const std::string& fulllabel, std::string& label, std::map<std::string, std::string>& metadata)
        {
            enum {kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue};
            int state = kLabel; int deep = 0;
            std::string key, value;
            
            for (unsigned int i = 0; i < fulllabel.size(); i++) {
                char c = fulllabel[i];
                switch (state) {
                    case kLabel :
                        assert(deep == 0);
                        switch (c) {
                            case '\\' : state = kEscape1; break;
                            case '[' : state = kKey; deep++; break;
                            default : label += c;
                        }
                        break;
                        
                    case kEscape1:
                        label += c;
                        state = kLabel;
                        break;
                        
                    case kEscape2:
                        key += c;
                        state = kKey;
                        break;
                        
                    case kEscape3:
                        value += c;
                        state = kValue;
                        break;
                        
                    case kKey:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape2;
                                break;
                                
                            case '[':
                                deep++;
                                key += c;
                                break;
                                
                            case ':':
                                if (deep == 1) {
                                    state = kValue;
                                } else {
                                    key += c;
                                }
                                break;
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = "";
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    key += c;
                                }
                                break;
                            default : key += c;
                        }
                        break;
                        
                    case kValue:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape3;
                                break;
                                
                            case '[':
                                deep++;
                                value += c;
                                break;
                                
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = rmWhiteSpaces(value);
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    value += c;
                                }
                                break;
                            default : value += c;
                        }
                        break;
                        
                    default:
                        fprintf(stderr, "ERROR unrecognized state %d\n", state);
                }
            }
            label = rmWhiteSpaces(label);
        }
        
        /**
         * Analyses the widget zone metadata declarations and takes appropriate actions.
         */
        void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            if (zone == 0) {
                // special zone 0 means group metadata
                if (strcmp(key, "tooltip") == 0) {
                    // only group tooltip are currently implemented
                    fGroupTooltip = formatTooltip(30, value);
                } else if ((strcmp(key, "hidden") == 0) && (strcmp(value, "1") == 0)) {
                    fHiddenSet.insert(zone);
                }
            } else {
                if (strcmp(key, "size") == 0) {
                    fGuiSize[zone] = atof(value);
                }
                else if (strcmp(key, "tooltip") == 0) {
                    fTooltip[zone] = formatTooltip(30, value);
                }
                else if (strcmp(key, "unit") == 0) {
                    fUnit[zone] = value;
                }
                else if ((strcmp(key, "hidden") == 0) && (strcmp(value, "1") == 0)) {
                    fHiddenSet.insert(zone);
                }
                else if (strcmp(key, "scale") == 0) {
                    if (strcmp(value, "log") == 0) {
                        fLogSet.insert(zone);
                    } else if (strcmp(value, "exp") == 0) {
                        fExpSet.insert(zone);
                    }
                }
                else if (strcmp(key, "style") == 0) {
                    if (strcmp(value, "knob") == 0) {
                        fKnobSet.insert(zone);
                    } else if (strcmp(value, "led") == 0) {
                        fLedSet.insert(zone);
                    } else if (strcmp(value, "numerical") == 0) {
                        fNumSet.insert(zone);
                    } else {
                        const char* p = value;
                        if (parseWord(p, "radio")) {
                            fRadioDescription[zone] = std::string(p);
                        } else if (parseWord(p, "menu")) {
                            fMenuDescription[zone] = std::string(p);
                        }
                    }
                }
            }
        }
    
};

#endif
/**************************  END  MetaDataUI.h **************************/

/*******************************************************************************
 * LayoutUI
 * This section defines the LayoutUI structure and associated classes.
 ******************************************************************************/

// Struct defining standard sizes for UI elements like knobs, sliders, buttons, etc.

struct LayoutItemSize {
    
    float kKnobWidth = 10.f;
    float kKnobHeight = 10.f;

    float kVSliderWidth = 10.f;
    float kVSliderHeight = 25.f;

    float kHSliderWidth = 25.f;
    float kHSliderHeight = 10.f;

    float kButtonWidth = 10.f;
    float kButtonHeight = 10.f;

    float kCheckButtonWidth = 10.f;
    float kCheckButtonHeight = 10.f;

    float kNumEntryWidth = 20.f;
    float kNumEntryHeight = 10.f;

    float kVBargraphWidth = 10.f;
    float kVBargraphHeight = 20.f;

    float kHBargraphWidth = 20.f;
    float kHBargraphHeight = 10.f;
    
    float kBorderX = 5.f;
    float kBorderY = 5.f;
    
};

// Global variable for item sizes
static LayoutItemSize gItemSize;

/**
 Main LayoutUI class inheriting from GenericUI, PathBuilder, and MetaDataUI.
 All UI leave items have a (x,y) position and a (width,height) size, and are kept in a hierarchy of Groups.
 The size of items (leaves and groups) can be read with getWidth/getHeight, and their position with getPosX/getPosY.
 The size of items (leaves and groups) can be set with setSize, and their position with setPos.
 
 The idea is to:
 - build the hierarchy of Groups using buildUserInterface, a top group (fCurrentGroup field) is created
 - the top group size can be read using getWidth/getHeight,
 - the top group size is set using setSize, so that all leave item size are set
 - the position is set using setPos, so that all leave item position are set
*/
struct LayoutUI : public GenericUI, public PathBuilder, public MetaDataUI
{

    // Base UI item class
    struct BaseUIItem {
        
        typedef std::shared_ptr<BaseUIItem> shared_item;
      
        std::string fLabel;
        
        BaseUIItem(const std::string& label):fLabel(label) {}
        virtual ~BaseUIItem() {}
        
        virtual float getPosX() { return 0.f; };
        virtual float getPosY() { return 0.f; };
        
        virtual float getBorderX() { return 0.f; };
        virtual float getBorderY() { return 0.f; };
        
        virtual float getWidth() { return 0.f; };
        virtual float getHeight() { return 0.f; };
        
        virtual void setSize(float width, float height) {}
        virtual void setPos(float top_x, float top_y) {}
        
        virtual std::ostream& print(std::ostream& file) { return file; }
    };
    
    // Derived class for leaf UI elements
    struct UIItem : BaseUIItem  {
        
        float fBorderX = 0.f;
        float fBorderY = 0.f;
        
        float fWidth = 0.f;
        float fHeight = 0.f;
        
        float fPosX = 0.f;
        float fPosY = 0.f;
        
        UIItem(const std::string& label,
                    float width = 0.0f,
                    float height = 0.0f)
            :BaseUIItem(label), fWidth(width), fHeight(height) {}
       
        float getPosX() override { return fPosX; };
        float getPosY() override { return fPosY; };
        
        float getBorderX() override { return fBorderX; };
        float getBorderY() override { return fBorderY; };
        
        float getWidth() override { return fWidth; }
        float getHeight() override { return fHeight; }
        
        // Adapt all leave sizes
        void setSize(float width, float height) override
        {
            fWidth = width;
            fHeight = height;
        }
        
        // Adapt all leave positions
        void setPos(float top_x, float top_y) override
        {
            fPosX = top_x;
            fPosY = top_y;
        }
        
        std::ostream& print(std::ostream& file) override
        {
            file << "Label = " << fLabel << std::endl;
            file << "fPosX = " << fPosX << " fPosY = " << fPosY << std::endl;
            file << "fWidth = " << fWidth << " fHeight = " << fHeight << std::endl;
            file << "--------------------------" << std::endl;
            return file;
        }
    };
    
    // Base grouping class for UI items
    struct Group : UIItem {
        
        typedef std::shared_ptr<Group> shared_group;
        
        std::vector <UIItem::shared_item> fItems;
        
        Group(const std::string& label):UIItem(label)
        {}
        virtual ~Group()
        {}
        
        void add(UIItem::shared_item item) { fItems.push_back(item); }
        
        // Base implementation
        virtual void setSize(float width, float height) override
        {
            float real_width = getWidth() - getBorderX();
            float real_height = getHeight() - getBorderY();
            
            float w_ratio = width / real_width;
            float h_ratio = height / real_height;
            
            for (const auto& it : fItems) {
                it->setSize(it->getWidth() * w_ratio, it->getHeight() * h_ratio);
            }
        }
        
    };
    
    /**
     For an horizontal group:
        - width is the sum of all item width
        - height is the max of all item height
        - items x pos is moving by each consecutive item width
        - all items have the same y pos
     */
    struct HGroup : Group {
        
        HGroup(const std::string& label):Group(label)
        {}
        
        float getWidth() override
        {
            float res = 0.f;
            for (const auto& it : fItems) {
                res += it->getWidth();
            }
            return res;
        }
        
        float getHeight() override
        {
            float res = 0.f;
            for (const auto& it : fItems) {
                res = std::max(res, it->getHeight());
            }
            return res;
        }
        
        void setPos(float top_x, float top_y) override
        {
            for (const auto& it : fItems) {
                it->setPos(top_x, top_y);
                top_x += it->getWidth();
            }
        }
        
        void setSize(float width, float height) override
        {
            float real_width = getWidth() - getBorderX();
            float real_height = getHeight() - getBorderY();
            
            float w_ratio = width / real_width;
            float h_ratio = height / real_height;
            
            // Force all items height with real_height
            for (const auto& it : fItems) {
                it->setSize(it->getWidth() * w_ratio, real_height * h_ratio);
            }
        }
        
    };
    
    /**
     For a vertical group:
        - width is the max of all item width
        - height is the sum of all item height
        - items y pos is moving by each consecutive item height
        - all items have the same x pos
     */
    struct VGroup : Group {
        
        VGroup(const std::string& label):Group(label)
        {}
        
        float getWidth() override
        {
            float res = 0.f;
            for (const auto& it : fItems) {
                res = std::max(res, it->getWidth());
            }
            return res;
        }
        
        float getHeight() override
        {
            float res = 0.f;
            for (const auto& it : fItems) {
                res += it->getHeight();
            }
            return res;
        }
        
        void setPos(float top_x, float top_y) override
        {
            for (const auto& it : fItems) {
                it->setPos(top_x, top_y);
                top_y += it->getHeight();
            }
        }
        
        void setSize(float width, float height) override
        {
            float real_width = getWidth() - getBorderX();
            float real_height = getHeight() - getBorderY();
            
            float w_ratio = width / real_width;
            float h_ratio = height / real_height;
            
            // Force all items width with real_width
            for (const auto& it : fItems) {
                it->setSize(real_width * w_ratio, it->getHeight() * h_ratio);
            }
        }
        
    };
    
    // Terminal item classes representing various UI elements
    struct Button : UIItem {
        
        Button(const std::string& label):UIItem(label, gItemSize.kButtonWidth, gItemSize.kButtonHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------Button----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    struct CheckButton : UIItem {
        
        CheckButton(const std::string& label):UIItem(label, gItemSize.kCheckButtonWidth, gItemSize.kCheckButtonHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------CheckButton----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    struct HSlider : UIItem {
        
        HSlider(const std::string& label):UIItem(label, gItemSize.kHSliderWidth, gItemSize.kHSliderHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------HSlider----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    struct VSlider : UIItem {
        
        VSlider(const std::string& label):UIItem(label, gItemSize.kVSliderWidth, gItemSize.kVSliderHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------VSlider----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    struct NumEntry : UIItem {
        
        NumEntry(const std::string& label):UIItem(label, gItemSize.kNumEntryWidth, gItemSize.kNumEntryHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------NumEntry----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    struct HBargraph : UIItem {
        
        HBargraph(const std::string& label):UIItem(label, gItemSize.kHBargraphWidth, gItemSize.kHBargraphHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------HBargraph----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    struct VBargraph : UIItem {
        
        VBargraph(const std::string& label):UIItem(label, gItemSize.kVBargraphWidth, gItemSize.kVBargraphHeight) {}
        
        std::ostream& print(std::ostream& file) override
        {
            file << "----------VBargraph----------" << std::endl;
            return UIItem::print(file);
        }
    };
    
    // Attributes for managing groups and UI elements
    Group::shared_group fCurrentGroup = nullptr;
    std::stack<Group::shared_group> fGroupStack;
    std::map<std::string, UIItem::shared_item> fPathItemMap;

    // Method definitions for adding and managing UI elements and groups
    void addItem(const char* label, UIItem::shared_item item)
    {
        fPathItemMap[buildPath(label)] = item;
        fCurrentGroup->add(item);
    }

    void addGroup(const char* label, Group::shared_group group)
    {
        pushLabel(label);
        if (fCurrentGroup) {
            fCurrentGroup->add(group);
            fGroupStack.push(fCurrentGroup);
        }
        fCurrentGroup = group;
    }

    LayoutUI() {}
    virtual ~LayoutUI() {}
    
    float getWidth()
    {
        return fCurrentGroup->getWidth();
    }
    
    float getHeight()
    {
        return fCurrentGroup->getHeight();
    }
    
    void setSize(float width, float height)
    {
        fCurrentGroup->setSize(width, height);
    }
    
    void setPos(float x_pos, float y_pos)
    {
        fCurrentGroup->setPos(x_pos, y_pos);
    }
    
    void setPosAndSize(float x_pos, float y_pos, float width, float height)
    {
        fCurrentGroup->setSize(width, height);
        fCurrentGroup->setPos(x_pos, y_pos);
    }

    // -- widget's layouts

    virtual void openTabBox(const char* label) override
    {
        pushLabel(label);
    }

    virtual void openHorizontalBox(const char* label) override
    {
        addGroup(label, std::make_shared<HGroup>(label));
    }

    virtual void openVerticalBox(const char* label) override
    {
        addGroup(label, std::make_shared<VGroup>(label));
    }

    virtual void closeBox() override
    {
        popLabel();
        if (fGroupStack.empty()) {
            // Nothing for now
        } else {
            fCurrentGroup = fGroupStack.top();
            fGroupStack.pop();
        }
    }

    // -- active widgets

    virtual void addButton(const char* label, FAUSTFLOAT* zone) override
    {
        addItem(label, std::make_shared<Button>(label));
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) override
    {
        addItem(label, std::make_shared<CheckButton>(label));
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
    {
        addItem(label, std::make_shared<VSlider>(label));
    }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
    {
        addItem(label, std::make_shared<HSlider>(label));
    }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
    {
        addItem(label, std::make_shared<NumEntry>(label));
    }

    // -- passive widgets

    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
    {
        addItem(label, std::make_shared<HBargraph>(label));
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
    {
        addItem(label, std::make_shared<VBargraph>(label));
    }

    // -- metadata declarations

    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) override
    {
        MetaDataUI::declare(zone, key, val);
    }
};

// Generic print function for UI items
template <typename T>
inline std::ostream& operator<<(std::ostream& file, std::shared_ptr<T> item)
{
    return item->print(file);
}

#endif // FAUST_LAYOUTUI_H
/**************************  END  LayoutUI.h **************************/
#endif
/************************** BEGIN meta.h *******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__


/**
 The base class of Meta handler to be used in dsp::metadata(Meta* m) method to retrieve (key, value) metadata.
 */
struct FAUST_API Meta {
    virtual ~Meta() {}
    virtual void declare(const char* key, const char* value) = 0;
};

#endif
/**************************  END  meta.h **************************/
/************************** BEGIN dummy-audio.h *************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dummy_audio__
#define __dummy_audio__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <iomanip>

#ifdef USE_PTHREAD
#include <pthread.h>
#else
#include <thread>
#endif

/************************** BEGIN dsp.h ********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>
#include <cstdint>


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API UI;
struct FAUST_API Meta;

/**
 * DSP memory manager.
 */

struct FAUST_API dsp_memory_manager {
    
    enum MemType { kInt32, kInt32_ptr, kFloat, kFloat_ptr, kDouble, kDouble_ptr, kQuad, kQuad_ptr, kFixedPoint, kFixedPoint_ptr, kObj, kObj_ptr, kSound, kSound_ptr };

    virtual ~dsp_memory_manager() = default;
    
    /**
     * Inform the Memory Manager with the number of expected memory zones.
     * @param count - the number of expected memory zones
     */
    virtual void begin(size_t count) {}
    
    /**
     * Give the Memory Manager information on a given memory zone.
     * @param name - the memory zone name
     * @param type - the memory zone type (in MemType)
     * @param size - the size in unit of the memory type of the memory zone
     * @param size_bytes - the size in bytes of the memory zone
     * @param reads - the number of Read access to the zone used to compute one frame
     * @param writes - the number of Write access to the zone used to compute one frame
     */
    virtual void info(const char* name, MemType type, size_t size, size_t size_bytes, size_t reads, size_t writes) {}
  
    /**
     * Inform the Memory Manager that all memory zones have been described,
     * to possibly start a 'compute the best allocation strategy' step.
     */
    virtual void end() {}
    
    /**
     * Allocate a memory zone.
     * @param size - the memory zone size in bytes
     */
    virtual void* allocate(size_t size) = 0;
    
    /**
     * Destroy a memory zone.
     * @param ptr - the memory zone pointer to be deallocated
     */
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class FAUST_API dsp {

    public:

        dsp() = default;
        virtual ~dsp() = default;

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Return the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state.
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceInit(int sample_rate) = 0;
    
        /**
         * Init instance constant state.
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual ::dsp* clone() = 0;
    
        /**
         * Trigger the Meta* m parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * Read all controllers (buttons, sliders, etc.), and update the DSP state to be used by 'frame' or 'compute'.
         * This method will be filled with the -ec (--external-control) option.
         */
        virtual void control() {}
    
        /**
         * DSP instance computation to process one single frame.
         *
         * Note that by default inputs and outputs buffers are supposed to be distinct memory zones,
         * so one cannot safely write frame(inputs, inputs).
         * The -inpl option can be used for that, but only in scalar mode for now.
         * This method will be filled with the -os (--one-sample) option.
         *
         * @param inputs - the input audio buffers as an array of FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of FAUSTFLOAT samples (eiher float, double or quad)
         */
        virtual void frame(FAUSTFLOAT* inputs, FAUSTFLOAT* outputs) {}
        
        /**
         * DSP instance computation to be called with successive in/out audio buffers.
         *
         * Note that by default inputs and outputs buffers are supposed to be distinct memory zones,
         * so one cannot safely write compute(count, inputs, inputs).
         * The -inpl compilation option can be used for that, but only in scalar mode for now.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT buffers
         * (containing either float, double or quad samples)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT buffers
         * (containing either float, double or quad samples)
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * Alternative DSP instance computation method for use by subclasses, incorporating an additional `date_usec` parameter,
         * which specifies the timestamp of the first sample in the audio buffers.
         *
         * @param date_usec - the timestamp in microsec given by audio driver. By convention timestamp of -1 means 'no timestamp conversion',
         * events already have a timestamp expressed in frames.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class FAUST_API decorator_dsp : public ::dsp {

    protected:

        ::dsp* fDSP;

    public:

        decorator_dsp(::dsp* dsp = nullptr):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() override { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() override { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) override { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() override { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) override { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) override { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) override { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() override { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() override { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() override { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) override { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void control() override { fDSP->control(); }
        virtual void frame(FAUSTFLOAT* inputs, FAUSTFLOAT* outputs) override { fDSP->frame(inputs, outputs); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) override { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) override { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class, used with LLVM and Interpreter backends
 * to create DSP instances from a compiled DSP program.
 */

class FAUST_API dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() = default;
    
    public:
    
        /* Return factory name */
        virtual std::string getName() = 0;
    
        /* Return factory SHA key */
        virtual std::string getSHAKey() = 0;
    
        /* Return factory expanded DSP code */
        virtual std::string getDSPCode() = 0;
    
        /* Return factory compile options */
        virtual std::string getCompileOptions() = 0;
    
        /* Get the Faust DSP factory list of library dependancies */
        virtual std::vector<std::string> getLibraryList() = 0;
    
        /* Get the list of all used includes */
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        /* Get warning messages list for a given compilation */
        virtual std::vector<std::string> getWarningMessages() = 0;
    
        /* Create a new DSP instance, to be deleted with C++ 'delete' */
        virtual ::dsp* createDSPInstance() = 0;
    
        /* Static tables initialization, possibly implemened in sub-classes*/
        virtual void classInit(int sample_rate) {};
    
        /* Set a custom memory manager to be used when creating instances */
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
    
        /* Return the currently set custom memory manager */
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

// Denormal handling

#if defined (__SSE__)
#include <xmmintrin.h>
#endif

class FAUST_API ScopedNoDenormals {
    
    private:
    
        intptr_t fpsr = 0;
        
        void setFpStatusRegister(intptr_t fpsr_aux) noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("msr fpcr, %0" : : "ri" (fpsr_aux));
        #elif defined (__SSE__)
            // The volatile keyword here is needed to workaround a bug in AppleClang 13.0
            // which aggressively optimises away the variable otherwise
            volatile uint32_t fpsr_w = static_cast<uint32_t>(fpsr_aux);
            _mm_setcsr(fpsr_w);
        #endif
        }
        
        void getFpStatusRegister() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("mrs %0, fpcr" : "=r" (fpsr));
        #elif defined (__SSE__)
            fpsr = static_cast<intptr_t>(_mm_getcsr());
        #endif
        }
    
    public:
    
        ScopedNoDenormals() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            intptr_t mask = (1 << 24 /* FZ */);
        #elif defined (__SSE__)
        #if defined (__SSE2__)
            intptr_t mask = 0x8040;
        #else
            intptr_t mask = 0x8000;
        #endif
        #else
            intptr_t mask = 0x0000;
        #endif
            getFpStatusRegister();
            setFpStatusRegister(fpsr | mask);
        }
        
        ~ScopedNoDenormals() noexcept
        {
            setFpStatusRegister(fpsr);
        }

};

#define AVOIDDENORMALS ScopedNoDenormals ftz_scope;

#endif

/************************** END dsp.h **************************/
/************************** BEGIN audio.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef __audio__
#define __audio__

#include <set>
#include <utility>

class dsp;

typedef void (* shutdown_callback)(const char* message, void* arg);

typedef void (* compute_callback)(void* arg);

class audio {
    
    protected:
    
        shutdown_callback fShutdown;    // Shutdown callback
        void* fShutdownArg;             // Shutdown callback data
    
        std::set<std::pair<compute_callback, void*> > fComputeCallbackList;
    
    public:
    
        audio():fShutdown(nullptr), fShutdownArg(nullptr) {}
        virtual ~audio() {}

        /**
         * Init the DSP.
         * @param name - the DSP name to be given to the audio driven
         * (could appear as a JACK client for instance)
         * @param dsp - the dsp that will be initialized with the driver sample rate
         *
         * @return true is sucessful, false in case of driver failure.
         **/
        virtual bool init(const char* name, ::dsp* dsp) = 0;
    
        /**
         * Start audio processing.
         * @return true is sucessful, false if case of driver failure.
         **/
        virtual bool start() = 0;
    
        /**
         * Stop audio processing.
         **/
        virtual void stop() = 0;
    
        void setShutdownCallback(shutdown_callback cb, void* arg)
        {
            fShutdown = cb;
            fShutdownArg = arg;
        }
    
        void addControlCallback(compute_callback cb, void* arg)
        {
            fComputeCallbackList.insert(std::make_pair(cb, arg));
        }
    
        bool removeControlCallback(compute_callback cb, void* arg)
        {
            return (fComputeCallbackList.erase(std::make_pair(cb, arg)) == 1);
        }
    
        void runControlCallbacks()
        {
            for (const auto& it : fComputeCallbackList) {
                it.first(it.second);
            }
        }
    
        // Return buffer size in frames.
        virtual int getBufferSize() = 0;
    
        // Return the driver sample rate in Hz.
        virtual int getSampleRate() = 0;

        // Return the driver hardware inputs number.
        virtual int getNumInputs() = 0;
    
        // Return the driver hardware outputs number.
        virtual int getNumOutputs() = 0;
    
        /**
         * @return Returns the average proportion of available CPU
         * being spent inside the audio callbacks (between 0.0 and 1.0).
         **/
        virtual float getCPULoad() { return 0.f; }
};
					
#endif
/**************************  END  audio.h **************************/

#define BUFFER_TO_RENDER 10

struct dummyaudio_base : public audio {
    
    virtual void render() = 0;
};

template <typename REAL>
class dummyaudio_real : public dummyaudio_base {
    
    private:
        
        ::dsp* fDSP;
        
        int fSampleRate;
        int fBufferSize;
        
        REAL** fInChannel;
        REAL** fOutChannel;
        
        int fNumInputs;
        int fNumOutputs;
        
        bool fRunning;
        
        int fRender;
        int fCount;
        int fSample;
        bool fManager;
        bool fExit;
    
        void runAux()
        {
            try {
                process();
            } catch (...) {
                if (fExit) exit(EXIT_FAILURE);
            }
        }
        
    #ifdef USE_PTHREAD
        pthread_t fAudioThread;
        static void* run(void* ptr)
        {
            static_cast<dummyaudio_real*>(ptr)->runAux();
        }
    #else
        std::thread* fAudioThread = nullptr;
        static void run(dummyaudio_real* audio)
        {
            audio->runAux();
        }
    #endif
        
        void process()
        {
            while (fRunning && (fRender-- > 0)) {
                if (fSample > 0) { std::cout << "Render one buffer\n"; }
                render();
            }
            fRunning = false;
        }
        
    public:
        
        dummyaudio_real(int sr, int bs,
                        int count = BUFFER_TO_RENDER,
                        int sample = -1,
                        bool manager = false,
                        bool exit = false)
        :fSampleRate(sr), fBufferSize(bs),
        fInChannel(nullptr), fOutChannel(nullptr),
        fNumInputs(-1), fNumOutputs(-1),
        fRender(0), fCount(count),
        fSample(sample), fManager(manager),
        fExit(exit)
        {}
        
        dummyaudio_real(int count = BUFFER_TO_RENDER)
        :fSampleRate(48000), fBufferSize(512),
        fInChannel(nullptr), fOutChannel(nullptr),
        fNumInputs(-1), fNumOutputs(-1),
        fRender(0), fCount(count),
        fSample(512), fManager(false),
        fExit(false)
        {}
        
        virtual ~dummyaudio_real()
        {
            for (int i = 0; i < fNumInputs; i++) {
                delete[] fInChannel[i];
            }
            for (int i = 0; i < fNumOutputs; i++) {
                delete[] fOutChannel[i];
            }
            delete [] fInChannel;
            delete [] fOutChannel;
        }
        
        virtual bool init(const char* name, ::dsp* dsp)
        {
            fDSP = dsp;
            
            // To be used in destructor
            fNumInputs = fDSP->getNumInputs();
            fNumOutputs = fDSP->getNumOutputs();
            
            fInChannel = new REAL*[fNumInputs];
            fOutChannel = new REAL*[fNumOutputs];
            
            for (int i = 0; i < fNumInputs; i++) {
                fInChannel[i] = new REAL[fBufferSize];
                memset(fInChannel[i], 0, sizeof(REAL) * fBufferSize);
            }
            for (int i = 0; i < fNumOutputs; i++) {
                fOutChannel[i] = new REAL[fBufferSize];
                memset(fOutChannel[i], 0, sizeof(REAL) * fBufferSize);
            }
            
            if (fManager) {
                // classInit is called elsewhere with a custom memory manager
                fDSP->instanceInit(fSampleRate);
            } else {
                fDSP->init(fSampleRate);
            }
            
            return true;
        }
        
        virtual bool start()
        {
            fRender = fCount;
            fRunning = true;
            if (fCount == INT_MAX) {
            #ifdef USE_PTHREAD
                if (pthread_create(&fAudioThread, 0, run, this) != 0) {
                    fRunning = false;
                }
            #else
                fAudioThread = new std::thread(dummyaudio_real::run, this);
            #endif
                return fRunning;
            } else {
                process();
                return true;
            }
        }
        
        virtual void stop()
        {
            if (fRunning) {
                fRunning = false;
            #ifdef USE_PTHREAD
                pthread_join(fAudioThread, 0);
            #else
                fAudioThread->join();
                delete fAudioThread;
                fAudioThread = 0;
            #endif
            }
        }
        
        void render()
        {

            
            fDSP->compute(fBufferSize, reinterpret_cast<FAUSTFLOAT**>(fInChannel), reinterpret_cast<FAUSTFLOAT**>(fOutChannel));
            if (fNumInputs > 0) {
                for (int frame = 0; frame < fSample; frame++) {
                    for (int chan = 0; chan < fNumInputs; chan++) {
                        std::cout << std::fixed << std::setprecision(10) << "\t chan " << chan << " in " << fInChannel[0][frame];
                    }
                    std::cout << std::endl;
                }
            }
            if (fNumOutputs > 0) {
                for (int frame = 0; frame < fSample; frame++) {
                    for (int chan = 0; chan < fNumOutputs; chan++) {
                        std::cout << std::fixed << std::setprecision(10) << "\t chan " << chan << " out " << fOutChannel[chan][frame];
                    }
                    std::cout << std::endl;
                }
            }
        }
        
        virtual int getBufferSize() noexcept { return fBufferSize; }
        virtual int getSampleRate() noexcept { return fSampleRate; }
        
        virtual int getNumInputs() noexcept { return fNumInputs; }
        virtual int getNumOutputs() noexcept { return fNumOutputs; }

        REAL** getOutput() { return fOutChannel; }
    
};

struct dummyaudio : public dummyaudio_real<FAUSTFLOAT> {
    
    dummyaudio(int sr, int bs,
               int count = BUFFER_TO_RENDER,
               int sample = -1,
               bool manager = false,
               bool exit = false)
    : dummyaudio_real(sr, bs, count, sample, manager, exit)
    {}
    
    dummyaudio(int count = BUFFER_TO_RENDER) : dummyaudio_real(count)
    {}
    
};

#endif
/**************************  END  dummy-audio.h **************************/
#ifdef FIXED_POINT
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2023 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 **************************************************************************/

#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <cmath>
// Code for ap_fixed type mode
#include "ap_fixed.h"

typedef ap_fixed<32,8,AP_RND_CONV,AP_SAT> fixpoint_t;

// m: position of the most significant bit of the value, without taking the sign bit into account
// l: LSB with negative coding
#define sfx_t(m,l) ap_fixed<((m+1)-l+1),(m+1)+1,AP_RND_CONV,AP_SAT>
#define ufx_t(m,l) ap_ufixed<((m+1)-l),(m+1),AP_RND_CONV,AP_SAT>

/*
// fx version
inline fixpoint_t fabsfx(fixpoint_t x)
{
    return fixpoint_t(std::fabs(float(x)));
}
inline fixpoint_t acosfx(fixpoint_t x)
{
    return fixpoint_t(std::acos(float(x)));
}
inline fixpoint_t asinfx(fixpoint_t x)
{
    return fixpoint_t(std::asin(float(x)));
}
inline fixpoint_t atanfx(fixpoint_t x)
{
    return fixpoint_t(std::atan(float(x)));
}
inline fixpoint_t atan2fx(fixpoint_t x, fixpoint_t y)
{
    return fixpoint_t(std::atan2(float(x), float(y)));
}
inline fixpoint_t ceilfx(fixpoint_t x)
{
    return fixpoint_t(std::ceil(float(x)));
}
inline fixpoint_t cosfx(fixpoint_t x)
{
    return fixpoint_t(std::cos(float(x)));
}
inline fixpoint_t expfx(fixpoint_t x)
{
    return fixpoint_t(std::exp(float(x)));
}
inline fixpoint_t exp2fx(fixpoint_t x)
{
    return fixpoint_t(std::exp2(float(x)));
}
inline fixpoint_t exp10fx(fixpoint_t x)
{
#ifdef __APPLE__
    return fixpoint_t(__exp10f(float(x)));
#else
    return fixpoint_t(std::exp10(float(x)));
#endif
}
inline fixpoint_t floorfx(fixpoint_t x)
{
    return fixpoint_t(std::floor(float(x)));
}
inline fixpoint_t fmodfx(fixpoint_t x, fixpoint_t y)
{
    return fixpoint_t(std::fmod(float(x), float(y)));
}
inline fixpoint_t logfx(fixpoint_t x)
{
    return fixpoint_t(std::log(float(x)));
}
inline fixpoint_t log2fx(fixpoint_t x)
{
    return fixpoint_t(std::log2(float(x)));
}
inline fixpoint_t log10fx(fixpoint_t x)
{
    return fixpoint_t(std::log10(float(x)));
}
inline fixpoint_t powfx(fixpoint_t x, fixpoint_t y)
{
    return fixpoint_t(std::pow(float(x), float(y)));
}
inline fixpoint_t remainderfx(fixpoint_t x, fixpoint_t y)
{
    return fixpoint_t(std::remainder(float(x), float(y)));
}
inline fixpoint_t rintfx(fixpoint_t x)
{
    return fixpoint_t(std::rint(float(x)));
}
inline fixpoint_t roundfx(fixpoint_t x)
{
    return fixpoint_t(std::round(float(x)));
}
inline fixpoint_t sinfx(fixpoint_t x)
{
    return fixpoint_t(std::sin(float(x)));
}
inline fixpoint_t sqrtfx(fixpoint_t x)
{
    return fixpoint_t(std::sqrt(float(x)));
}
inline fixpoint_t tanfx(fixpoint_t x)
{
    return fixpoint_t(std::tan(float(x)));
}
// min/max
inline fixpoint_t fminfx(fixpoint_t x, fixpoint_t y)
{
    return fixpoint_t(std::min(float(x), float(y)));
}
inline fixpoint_t fmaxfx(fixpoint_t x, fixpoint_t y)
{
    return fixpoint_t(std::max(float(x), float(y)));
}
*/

// fx version
inline float fabsfx(float x)
{
    return std::fabs(x);
}
inline float acosfx(float x)
{
    return std::acos(x);
}
inline float asinfx(float x)
{
    return std::asin(x);
}
inline float atanfx(float x)
{
    return std::atan(x);
}
inline float atan2fx(float x, float y)
{
    return std::atan2(x, y);
}
inline float ceilfx(float x)
{
    return std::ceil(x);
}
inline float cosfx(float x)
{
    return std::cos(x);
}
inline float expfx(float x)
{
    return std::exp(x);
}
inline float exp2fx(float x)
{
    return std::exp2(x);
}
inline float exp10fx(float x)
{
#ifdef __APPLE__
    return __exp10f(x);
#else
    return exp10(x);
#endif
}
inline float floorfx(float x)
{
    return std::floor(x);
}
inline float fmodfx(float x, float y)
{
    return std::fmod(x, y);
}
inline float logfx(float x)
{
    return std::log(x);
}
inline float log2fx(float x)
{
    return std::log2(x);
}
inline float log10fx(float x)
{
    return std::log10(x);
}
inline float powfx(float x, float y)
{
    return std::pow(x, y);
}
inline float remainderfx(float x, float y)
{
    return std::remainder(x, y);
}
inline float rintfx(float x)
{
    return std::rint(x);
}
inline float roundfx(float x)
{
    return std::round(x);
}
inline float sinfx(float x)
{
    return std::sin(x);
}
inline float sqrtfx(float x)
{
    return std::sqrt(x);
}
inline float tanfx(float x)
{
    return std::tan(x);
}
// min/max
/*
#define minfx(x, y) { (((x) < (y)) ? (x) : (y)) }
#define maxfx(x, y) { (((x) < (y)) ? (y) : (x)) }
*/

// For C++ backend
inline float minfx(float x, float y) { return (x < y) ? x : y; }
inline float maxfx(float x, float y) { return (x < y) ? y : x; }

// For C backend
inline float fminfx(float x, float y) { return (x < y) ? x : y; }
inline float fmaxfx(float x, float y) { return (x < y) ? y : x; }

#endif
#endif

// faust -a minimal.cpp noise.dsp -o noise.cpp && c++ -std=c++11 noise.cpp -o noise && ./noise

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec2[2];
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	int iRec5[2];
	float fRec4[3];
	float fConst18;
	float fRec3[3];
	float fConst19;
	float fRec1[3];
	float fConst20;
	float fConst21;
	float fConst22;
	float fRec6[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec7[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec8[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec9[3];
	float fConst32;
	float fConst33;
	float fConst34;
	float fRec10[3];
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec11[3];
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec12[3];
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec13[3];
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec14[3];
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec15[3];
	float fConst50;
	float fConst51;
	float fConst52;
	float fRec16[3];
	float fConst53;
	float fConst54;
	float fConst55;
	float fRec17[3];
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec18[3];
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec19[3];
	float fConst62;
	float fConst63;
	float fConst64;
	float fRec20[3];
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec21[3];
	float fConst68;
	float fConst69;
	float fConst70;
	float fRec22[3];
	float fConst71;
	float fConst72;
	float fConst73;
	float fRec23[3];
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec24[3];
	int IOTA0;
	float fVec1[1048576];
	int iConst77;
	FAUSTFLOAT fHslider1;
	float fRec25[2];
	float fRec26[2];
	int iRec27[2];
	int iRec28[2];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider4;
	float fVec2[1048576];
	FAUSTFLOAT fHslider5;
	float fRec30[2];
	float fRec31[2];
	int iRec32[2];
	int iRec33[2];
	float fRec29[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider8;
	float fVec3[1048576];
	FAUSTFLOAT fHslider9;
	float fRec35[2];
	float fRec36[2];
	int iRec37[2];
	int iRec38[2];
	float fRec34[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fHslider12;
	float fVec4[1048576];
	FAUSTFLOAT fHslider13;
	float fRec40[2];
	float fRec41[2];
	int iRec42[2];
	int iRec43[2];
	float fRec39[2];
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider16;
	
 public:
	mydsp() {
	}
	
	mydsp(const mydsp&) = default;
	
	virtual ~mydsp() = default;
	
	mydsp& operator=(const mydsp&) = default;
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.22.0");
		m->declare("compile_options", "-a minimal.cpp -lang cpp -i -fpga-mem-th 4 -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "multiheadFeedback.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "multiheadFeedback");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.5.0");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "1.2.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "1.2.1");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = std::pow(0.001f, 1.6666666f / fConst0);
		fConst2 = mydsp_faustpower2_f(fConst1);
		fConst3 = 2.0f * std::cos(691.1504f / fConst0) * fConst1;
		fConst4 = 1.0f / std::max<float>(1.0f, 0.001f * fConst0);
		fConst5 = std::tan(15707.963f / fConst0);
		fConst6 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fConst5));
		fConst7 = 1.0f / fConst5;
		fConst8 = (fConst7 + -1.4142135f) / fConst5 + 1.0f;
		fConst9 = (fConst7 + 1.4142135f) / fConst5 + 1.0f;
		fConst10 = 1.0f / fConst9;
		fConst11 = std::tan(596.9026f / fConst0);
		fConst12 = mydsp_faustpower2_f(fConst11);
		fConst13 = 2.0f * (1.0f - 1.0f / fConst12);
		fConst14 = 1.0f / fConst11;
		fConst15 = (fConst14 + -1.4142135f) / fConst11 + 1.0f;
		fConst16 = (fConst14 + 1.4142135f) / fConst11 + 1.0f;
		fConst17 = 1.0f / fConst16;
		fConst18 = 1.0f / (fConst12 * fConst16);
		fConst19 = 0.8f / fConst9;
		fConst20 = std::pow(0.001f, 33.333332f / fConst0);
		fConst21 = mydsp_faustpower2_f(fConst20);
		fConst22 = 2.0f * std::cos(24567.254f / fConst0) * fConst20;
		fConst23 = std::pow(0.001f, 16.666666f / fConst0);
		fConst24 = mydsp_faustpower2_f(fConst23);
		fConst25 = 2.0f * std::cos(23310.617f / fConst0) * fConst23;
		fConst26 = std::pow(0.001f, 11.111111f / fConst0);
		fConst27 = mydsp_faustpower2_f(fConst26);
		fConst28 = 2.0f * std::cos(22053.98f / fConst0) * fConst26;
		fConst29 = std::pow(0.001f, 8.333333f / fConst0);
		fConst30 = mydsp_faustpower2_f(fConst29);
		fConst31 = 2.0f * std::cos(20797.344f / fConst0) * fConst29;
		fConst32 = std::pow(0.001f, 6.6666665f / fConst0);
		fConst33 = mydsp_faustpower2_f(fConst32);
		fConst34 = 2.0f * std::cos(19540.707f / fConst0) * fConst32;
		fConst35 = std::pow(0.001f, 5.5555553f / fConst0);
		fConst36 = mydsp_faustpower2_f(fConst35);
		fConst37 = 2.0f * std::cos(18284.068f / fConst0) * fConst35;
		fConst38 = std::pow(0.001f, 4.7619047f / fConst0);
		fConst39 = mydsp_faustpower2_f(fConst38);
		fConst40 = 2.0f * std::cos(17027.432f / fConst0) * fConst38;
		fConst41 = std::pow(0.001f, 4.1666665f / fConst0);
		fConst42 = mydsp_faustpower2_f(fConst41);
		fConst43 = 2.0f * std::cos(15770.795f / fConst0) * fConst41;
		fConst44 = std::pow(0.001f, 3.7037036f / fConst0);
		fConst45 = mydsp_faustpower2_f(fConst44);
		fConst46 = 2.0f * std::cos(14514.158f / fConst0) * fConst44;
		fConst47 = std::pow(0.001f, 3.3333333f / fConst0);
		fConst48 = mydsp_faustpower2_f(fConst47);
		fConst49 = 2.0f * std::cos(13257.521f / fConst0) * fConst47;
		fConst50 = std::pow(0.001f, 3.030303f / fConst0);
		fConst51 = mydsp_faustpower2_f(fConst50);
		fConst52 = 2.0f * std::cos(12000.884f / fConst0) * fConst50;
		fConst53 = std::pow(0.001f, 2.7777777f / fConst0);
		fConst54 = mydsp_faustpower2_f(fConst53);
		fConst55 = 2.0f * std::cos(10744.247f / fConst0) * fConst53;
		fConst56 = std::pow(0.001f, 2.5641026f / fConst0);
		fConst57 = mydsp_faustpower2_f(fConst56);
		fConst58 = 2.0f * std::cos(9487.609f / fConst0) * fConst56;
		fConst59 = std::pow(0.001f, 2.3809524f / fConst0);
		fConst60 = mydsp_faustpower2_f(fConst59);
		fConst61 = 2.0f * std::cos(8230.973f / fConst0) * fConst59;
		fConst62 = std::pow(0.001f, 2.2222223f / fConst0);
		fConst63 = mydsp_faustpower2_f(fConst62);
		fConst64 = 2.0f * std::cos(6974.3354f / fConst0) * fConst62;
		fConst65 = std::pow(0.001f, 2.0833333f / fConst0);
		fConst66 = mydsp_faustpower2_f(fConst65);
		fConst67 = 2.0f * std::cos(5717.6987f / fConst0) * fConst65;
		fConst68 = std::pow(0.001f, 1.9607843f / fConst0);
		fConst69 = mydsp_faustpower2_f(fConst68);
		fConst70 = 2.0f * std::cos(4461.0615f / fConst0) * fConst68;
		fConst71 = std::pow(0.001f, 1.8518518f / fConst0);
		fConst72 = mydsp_faustpower2_f(fConst71);
		fConst73 = 2.0f * std::cos(3204.4246f / fConst0) * fConst71;
		fConst74 = std::pow(0.001f, 1.754386f / fConst0);
		fConst75 = mydsp_faustpower2_f(fConst74);
		fConst76 = 2.0f * std::cos(1947.7875f / fConst0) * fConst74;
		iConst77 = static_cast<int>(4.0f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(0.3f);
		fButton0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider5 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox1 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider8 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider9 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider10 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider11 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox2 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider12 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider13 = static_cast<FAUSTFLOAT>(0.2f);
		fHslider14 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider15 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox3 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider16 = static_cast<FAUSTFLOAT>(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec2[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec5[l2] = 0;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = l7 + 1) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = l8 + 1) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = l10 + 1) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = l11 + 1) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = l12 + 1) {
			fRec12[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = l14 + 1) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = l15 + 1) {
			fRec15[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = l16 + 1) {
			fRec16[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = l17 + 1) {
			fRec17[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = l18 + 1) {
			fRec18[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 3; l19 = l19 + 1) {
			fRec19[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 3; l20 = l20 + 1) {
			fRec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 3; l21 = l21 + 1) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 3; l22 = l22 + 1) {
			fRec22[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = l23 + 1) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 3; l24 = l24 + 1) {
			fRec24[l24] = 0.0f;
		}
		IOTA0 = 0;
		for (int l25 = 0; l25 < 1048576; l25 = l25 + 1) {
			fVec1[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec25[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			iRec27[l28] = 0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			iRec28[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec0[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 1048576; l31 = l31 + 1) {
			fVec2[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec30[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec31[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			iRec32[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			iRec33[l35] = 0;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec29[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 1048576; l37 = l37 + 1) {
			fVec3[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec35[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec36[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			iRec37[l40] = 0;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			iRec38[l41] = 0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec34[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 1048576; l43 = l43 + 1) {
			fVec4[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec40[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec41[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			iRec42[l46] = 0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			iRec43[l47] = 0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec39[l48] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("multiheadFeedback");
		ui_interface->addHorizontalSlider("Global Mix", &fHslider16, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 0/Feedback", &fHslider12, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 0/Level", &fHslider15, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 0/Pan", &fHslider14, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider13, "unit", "s");
		ui_interface->addHorizontalSlider("Head 0/Time", &fHslider13, FAUSTFLOAT(0.2f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.001f));
		ui_interface->addCheckButton("Head 0/on", &fCheckbox3);
		ui_interface->addHorizontalSlider("Head 1/Feedback", &fHslider8, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 1/Level", &fHslider11, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 1/Pan", &fHslider10, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider9, "unit", "s");
		ui_interface->addHorizontalSlider("Head 1/Time", &fHslider9, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.001f));
		ui_interface->addCheckButton("Head 1/on", &fCheckbox2);
		ui_interface->addHorizontalSlider("Head 2/Feedback", &fHslider4, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 2/Level", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 2/Pan", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "unit", "s");
		ui_interface->addHorizontalSlider("Head 2/Time", &fHslider5, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.001f));
		ui_interface->addCheckButton("Head 2/on", &fCheckbox1);
		ui_interface->addHorizontalSlider("Head 3/Feedback", &fHslider0, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 3/Level", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Head 3/Pan", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "unit", "s");
		ui_interface->addHorizontalSlider("Head 3/Time", &fHslider1, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.001f));
		ui_interface->addCheckButton("Head 3/on", &fCheckbox0);
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = static_cast<float>(fHslider0);
		float fSlow1 = static_cast<float>(fButton0);
		int iSlow2 = static_cast<int>(fConst0 * static_cast<float>(fHslider1));
		float fSlow3 = static_cast<float>(fHslider2);
		float fSlow4 = static_cast<float>(fHslider3);
		float fSlow5 = static_cast<float>(fCheckbox0);
		float fSlow6 = fSlow5 * fSlow4 * (1.0f - fSlow3);
		float fSlow7 = static_cast<float>(fHslider4);
		int iSlow8 = static_cast<int>(fConst0 * static_cast<float>(fHslider5));
		float fSlow9 = static_cast<float>(fHslider6);
		float fSlow10 = static_cast<float>(fHslider7);
		float fSlow11 = static_cast<float>(fCheckbox1);
		float fSlow12 = fSlow11 * fSlow10 * (1.0f - fSlow9);
		float fSlow13 = static_cast<float>(fHslider8);
		int iSlow14 = static_cast<int>(fConst0 * static_cast<float>(fHslider9));
		float fSlow15 = static_cast<float>(fHslider10);
		float fSlow16 = static_cast<float>(fHslider11);
		float fSlow17 = static_cast<float>(fCheckbox2);
		float fSlow18 = fSlow17 * fSlow16 * (1.0f - fSlow15);
		float fSlow19 = static_cast<float>(fHslider12);
		int iSlow20 = static_cast<int>(fConst0 * static_cast<float>(fHslider13));
		float fSlow21 = static_cast<float>(fHslider14);
		float fSlow22 = static_cast<float>(fHslider15);
		float fSlow23 = static_cast<float>(fCheckbox3);
		float fSlow24 = fSlow23 * fSlow22 * (1.0f - fSlow21);
		float fSlow25 = static_cast<float>(fHslider16);
		float fSlow26 = 0.05f * (1.0f - fSlow25);
		float fSlow27 = fSlow3 * fSlow5 * fSlow4;
		float fSlow28 = fSlow9 * fSlow11 * fSlow10;
		float fSlow29 = fSlow15 * fSlow17 * fSlow16;
		float fSlow30 = fSlow21 * fSlow23 * fSlow22;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fVec0[0] = fSlow1;
			iRec2[0] = (iRec2[1] + (iRec2[1] > 0)) * (fSlow1 <= fVec0[1]) + (fSlow1 > fVec0[1]);
			float fTemp0 = fConst4 * static_cast<float>(iRec2[0]);
			iRec5[0] = 1103515245 * iRec5[1] + 12345;
			fRec4[0] = 4.656613e-10f * static_cast<float>(iRec5[0]) - fConst17 * (fConst15 * fRec4[2] + fConst13 * fRec4[1]);
			fRec3[0] = fConst18 * (fRec4[2] + (fRec4[0] - 2.0f * fRec4[1])) - fConst10 * (fConst8 * fRec3[2] + fConst6 * fRec3[1]);
			float fTemp1 = fConst19 * (fRec3[2] + fRec3[0] + 2.0f * fRec3[1]) * std::max<float>(0.0f, std::min<float>(fTemp0, 2.0f - fTemp0));
			fRec1[0] = fTemp1 + fConst3 * fRec1[1] - fConst2 * fRec1[2];
			fRec6[0] = fTemp1 + fConst22 * fRec6[1] - fConst21 * fRec6[2];
			fRec7[0] = fTemp1 + fConst25 * fRec7[1] - fConst24 * fRec7[2];
			fRec8[0] = fTemp1 + fConst28 * fRec8[1] - fConst27 * fRec8[2];
			fRec9[0] = fTemp1 + fConst31 * fRec9[1] - fConst30 * fRec9[2];
			fRec10[0] = fTemp1 + fConst34 * fRec10[1] - fConst33 * fRec10[2];
			fRec11[0] = fTemp1 + fConst37 * fRec11[1] - fConst36 * fRec11[2];
			fRec12[0] = fTemp1 + fConst40 * fRec12[1] - fConst39 * fRec12[2];
			fRec13[0] = fTemp1 + fConst43 * fRec13[1] - fConst42 * fRec13[2];
			fRec14[0] = fTemp1 + fConst46 * fRec14[1] - fConst45 * fRec14[2];
			fRec15[0] = fTemp1 + fConst49 * fRec15[1] - fConst48 * fRec15[2];
			fRec16[0] = fTemp1 + fConst52 * fRec16[1] - fConst51 * fRec16[2];
			fRec17[0] = fTemp1 + fConst55 * fRec17[1] - fConst54 * fRec17[2];
			fRec18[0] = fTemp1 + fConst58 * fRec18[1] - fConst57 * fRec18[2];
			fRec19[0] = fTemp1 + fConst61 * fRec19[1] - fConst60 * fRec19[2];
			fRec20[0] = fTemp1 + fConst64 * fRec20[1] - fConst63 * fRec20[2];
			fRec21[0] = fTemp1 + fConst67 * fRec21[1] - fConst66 * fRec21[2];
			fRec22[0] = fTemp1 + fConst70 * fRec22[1] - fConst69 * fRec22[2];
			fRec23[0] = fTemp1 + fConst73 * fRec23[1] - fConst72 * fRec23[2];
			fRec24[0] = fTemp1 + fConst76 * fRec24[1] - fConst75 * fRec24[2];
			float fTemp2 = fRec1[0] + 0.25f * (fRec24[0] - fRec24[2]) + 0.11111111f * (fRec23[0] - fRec23[2]) + 0.0625f * (fRec22[0] - fRec22[2]) + 0.04f * (fRec21[0] - fRec21[2]) + 0.027777778f * (fRec20[0] - fRec20[2]) + 0.020408163f * (fRec19[0] - fRec19[2]) + 0.015625f * (fRec18[0] - fRec18[2]) + 0.012345679f * (fRec17[0] - fRec17[2]) + 0.01f * (fRec16[0] - fRec16[2]) + 0.008264462f * (fRec15[0] - fRec15[2]) + 0.0069444445f * (fRec14[0] - fRec14[2]) + 0.00591716f * (fRec13[0] - fRec13[2]) + 0.0051020407f * (fRec12[0] - fRec12[2]) + 0.0044444446f * (fRec11[0] - fRec11[2]) + 0.00390625f * (fRec10[0] - fRec10[2]) + 0.0034602077f * (fRec9[0] - fRec9[2]) + 0.0030864198f * (fRec8[0] - fRec8[2]) + 0.002770083f * (fRec7[0] - fRec7[2]) + 0.0025f * (fRec6[0] - fRec6[2]) - fRec1[2];
			float fTemp3 = 0.05f * fTemp2;
			float fTemp4 = fTemp3 + fSlow0 * fRec0[1];
			fVec1[IOTA0 & 1048575] = fTemp4;
			float fTemp5 = ((fRec25[1] != 0.0f) ? (((fRec26[1] > 0.0f) & (fRec26[1] < 1.0f)) ? fRec25[1] : 0.0f) : (((fRec26[1] == 0.0f) & (iSlow2 != iRec27[1])) ? 0.0009765625f : (((fRec26[1] == 1.0f) & (iSlow2 != iRec28[1])) ? -0.0009765625f : 0.0f)));
			fRec25[0] = fTemp5;
			fRec26[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec26[1] + fTemp5));
			iRec27[0] = (((fRec26[1] >= 1.0f) & (iRec28[1] != iSlow2)) ? iSlow2 : iRec27[1]);
			iRec28[0] = (((fRec26[1] <= 0.0f) & (iRec27[1] != iSlow2)) ? iSlow2 : iRec28[1]);
			float fTemp6 = fVec1[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec27[0]))) & 1048575];
			fRec0[0] = fTemp6 + fRec26[0] * (fVec1[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec28[0]))) & 1048575] - fTemp6);
			float fTemp7 = fTemp3 + fSlow7 * fRec29[1];
			fVec2[IOTA0 & 1048575] = fTemp7;
			float fTemp8 = ((fRec30[1] != 0.0f) ? (((fRec31[1] > 0.0f) & (fRec31[1] < 1.0f)) ? fRec30[1] : 0.0f) : (((fRec31[1] == 0.0f) & (iSlow8 != iRec32[1])) ? 0.0009765625f : (((fRec31[1] == 1.0f) & (iSlow8 != iRec33[1])) ? -0.0009765625f : 0.0f)));
			fRec30[0] = fTemp8;
			fRec31[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec31[1] + fTemp8));
			iRec32[0] = (((fRec31[1] >= 1.0f) & (iRec33[1] != iSlow8)) ? iSlow8 : iRec32[1]);
			iRec33[0] = (((fRec31[1] <= 0.0f) & (iRec32[1] != iSlow8)) ? iSlow8 : iRec33[1]);
			float fTemp9 = fVec2[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec32[0]))) & 1048575];
			fRec29[0] = fTemp9 + fRec31[0] * (fVec2[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec33[0]))) & 1048575] - fTemp9);
			float fTemp10 = fTemp3 + fSlow13 * fRec34[1];
			fVec3[IOTA0 & 1048575] = fTemp10;
			float fTemp11 = ((fRec35[1] != 0.0f) ? (((fRec36[1] > 0.0f) & (fRec36[1] < 1.0f)) ? fRec35[1] : 0.0f) : (((fRec36[1] == 0.0f) & (iSlow14 != iRec37[1])) ? 0.0009765625f : (((fRec36[1] == 1.0f) & (iSlow14 != iRec38[1])) ? -0.0009765625f : 0.0f)));
			fRec35[0] = fTemp11;
			fRec36[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec36[1] + fTemp11));
			iRec37[0] = (((fRec36[1] >= 1.0f) & (iRec38[1] != iSlow14)) ? iSlow14 : iRec37[1]);
			iRec38[0] = (((fRec36[1] <= 0.0f) & (iRec37[1] != iSlow14)) ? iSlow14 : iRec38[1]);
			float fTemp12 = fVec3[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec37[0]))) & 1048575];
			fRec34[0] = fTemp12 + fRec36[0] * (fVec3[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec38[0]))) & 1048575] - fTemp12);
			float fTemp13 = fTemp3 + fSlow19 * fRec39[1];
			fVec4[IOTA0 & 1048575] = fTemp13;
			float fTemp14 = ((fRec40[1] != 0.0f) ? (((fRec41[1] > 0.0f) & (fRec41[1] < 1.0f)) ? fRec40[1] : 0.0f) : (((fRec41[1] == 0.0f) & (iSlow20 != iRec42[1])) ? 0.0009765625f : (((fRec41[1] == 1.0f) & (iSlow20 != iRec43[1])) ? -0.0009765625f : 0.0f)));
			fRec40[0] = fTemp14;
			fRec41[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec41[1] + fTemp14));
			iRec42[0] = (((fRec41[1] >= 1.0f) & (iRec43[1] != iSlow20)) ? iSlow20 : iRec42[1]);
			iRec43[0] = (((fRec41[1] <= 0.0f) & (iRec42[1] != iSlow20)) ? iSlow20 : iRec43[1]);
			float fTemp15 = fVec4[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec42[0]))) & 1048575];
			fRec39[0] = fTemp15 + fRec41[0] * (fVec4[(IOTA0 - std::min<int>(iConst77, std::max<int>(0, iRec43[0]))) & 1048575] - fTemp15);
			float fTemp16 = fSlow26 * fTemp2;
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp16 + fSlow25 * (fSlow24 * fRec39[0] + fSlow18 * fRec34[0] + fSlow12 * fRec29[0] + fSlow6 * fRec0[0]));
			output1[i0] = static_cast<FAUSTFLOAT>(fTemp16 + fSlow25 * (fSlow30 * fRec39[0] + fSlow29 * fRec34[0] + fSlow28 * fRec29[0] + fSlow27 * fRec0[0]));
			fVec0[1] = fVec0[0];
			iRec2[1] = iRec2[0];
			iRec5[1] = iRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			IOTA0 = IOTA0 + 1;
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			iRec27[1] = iRec27[0];
			iRec28[1] = iRec28[0];
			fRec0[1] = fRec0[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			iRec32[1] = iRec32[0];
			iRec33[1] = iRec33[0];
			fRec29[1] = fRec29[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			iRec37[1] = iRec37[0];
			iRec38[1] = iRec38[0];
			fRec34[1] = fRec34[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			iRec42[1] = iRec42[0];
			iRec43[1] = iRec43[0];
			fRec39[1] = fRec39[0];
		}
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

using namespace std;

#ifdef LAYOUT_UI
void getMinimumSize(dsp* dsp, LayoutUI* ui, float& width, float& height)
{
    // Prepare layout
    dsp->buildUserInterface(ui);
    
    cout << "==========================" << endl;
    for (const auto& it : ui->fPathItemMap) {
        cout << it.second << endl;
    }
    
    cout << "Width " << ui->getWidth() << endl;
    cout << "Height " << ui->getHeight() << endl;
    
    width = ui->getWidth();
    height = ui->getHeight();
}

void setPosAndSize(LayoutUI* ui, float x_pos, float y_pos, float width, float height)
{
    ui->setSize(width, height);
    ui->setPos(x_pos, y_pos);
    
    cout << "==========================" << endl;
    for (const auto& it : ui->fPathItemMap) {
        cout << it.second << endl;
    }
    
    cout << "Width " << ui->getWidth() << endl;
    cout << "Height " << ui->getHeight() << endl;
}
#endif

/******************* END minimal.cpp ****************/


#endif
