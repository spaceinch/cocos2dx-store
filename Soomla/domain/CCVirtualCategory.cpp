/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

// Created by Fedor Shubin on 5/19/13.

#include "CCVirtualCategory.h"

USING_NS_CC;

namespace soomla {
    CCVirtualCategory *CCVirtualCategory::create(__String *name, __Array *goodItemIds) {
        CCVirtualCategory *ret = new CCVirtualCategory();
        ret->autorelease();
        ret->init(name, goodItemIds);
        return ret;
    }

    CCVirtualCategory *CCVirtualCategory::createWithDictionary(__Dictionary *dict) {
        CCVirtualCategory *ret = new CCVirtualCategory();
        ret->autorelease();
        ret->initWithDictionary(dict);
        return ret;
    }

    bool CCVirtualCategory::init(__String *name, __Array *goodItemIds) {
        setName(name);
        setGoodItemIds(goodItemIds);

        return true;
    }

    bool CCVirtualCategory::initWithDictionary(__Dictionary *dict) {
        fillNameFromDict(dict);
        fillGoodItemIdsFromDict(dict);

        return true;
    }

    __Dictionary *CCVirtualCategory::toDictionary() {
        __Dictionary *dict = __Dictionary::create();

        putNameToDict(dict);
        putGoodItemIdsToDict(dict);

        return dict;
    }

    CCVirtualCategory::~CCVirtualCategory() {
        CC_SAFE_RELEASE(mName);
        CC_SAFE_RELEASE(mGoodItemIds);
    }
}
