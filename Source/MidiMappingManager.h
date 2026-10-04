#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <map>

// ABYSS MIDI mapping storage helper.
// Stores CC -> parameter index mappings and can be extended to persist in ValueTree.
class AbyssMidiMappingManager
{
public:
    void learn(int cc, int parameter) { mappings[cc] = parameter; }
    void remove(int cc) { mappings.erase(cc); }
    int parameterForCC(int cc) const
    {
        auto it = mappings.find(cc);
        return it == mappings.end() ? -1 : it->second;
    }
private:
    std::map<int,int> mappings;
};
