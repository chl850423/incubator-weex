/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#pragma once

#include "JSDestructibleObject.h"
#include "Structure.h"
#include "TemplateRegistryKey.h"

namespace JSC {

class JSTemplateRegistryKey final : public JSDestructibleObject {
public:
    typedef JSDestructibleObject Base;

    static JSTemplateRegistryKey* create(VM&, Ref<TemplateRegistryKey>&&);

    static Structure* createStructure(VM& vm, JSGlobalObject* globalObject, JSValue prototype)
    {
        return Structure::create(vm, globalObject, prototype, TypeInfo(ObjectType, StructureFlags), info());
    }

    DECLARE_INFO;

    const TemplateRegistryKey& templateRegistryKey() const { return m_templateRegistryKey.get(); }

protected:
    static void destroy(JSCell*);

private:
    JSTemplateRegistryKey(VM&, Ref<TemplateRegistryKey>&&);

    Ref<TemplateRegistryKey> m_templateRegistryKey;
};

} // namespace JSC
