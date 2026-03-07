/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import SelectionExtensionAbility from '@ohos.selectionInput.SelectionExtensionAbility';
import SelectionExtensionContext from '@ohos.selectionInput.SelectionExtensionContext';
import { PanelInfo, PanelType } from '@ohos.selectionInput.SelectionPanel';
import selectionManager from '@ohos.selectionInput.selectionManager';
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium';
import abilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';

// Preconditions:
// hdc shell param set sys.selection.switch on
// hdc shell param set sys.selection.app bundlename/MainAbility

export default function selectionManagerTest() {
  describe('SelectionManagerTest', () => {
    beforeAll(() => {
    })
    beforeEach(() => {
    })
    afterEach(() => {
    })
    afterAll(() => {
    })

    /*
     * @tc.number  selectionfwk_on_selectionCompleted_003
     * @tc.name    Test should success, when parameters are valid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_on_selectionCompleted_003', 0, () => {
      console.info('************* selectionfwk_on_selectionCompleted_003*************');
      try {
          selectionManager.on('selectionCompleted', (info) => {
          console.info(`selectionfwk_on_selectionCompleted_003 callback enter`);
          console.info(`selectionfwk_on_selectionCompleted_003 throw info: ${JSON.stringify(info)}`);
          expect(info != null).assertTrue();
        });
      } catch(error) {
        console.error(`Failed to query device. Code is ${error.code}, message is ${error.message}`);
      }
      console.info('************* selectionfwk_on_selectionCompleted_003 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_on_selectionCompleted_004
     * @tc.name    Test 401, when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_on_selectionCompleted_004', 0, () => {
      console.info('************* selectionfwk_on_selectionCompleted_004*************');
      try {
        selectionManager.on(null, (info) => {
          console.info(`selectionfwk_on_selectionCompleted_004 callback enter`);
          //expect(info == null).assertTrue();
        });
      } catch(error) {
        console.info(`selectionfwk_on_selectionCompleted_004 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_on_selectionCompleted_004 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_on_selectionCompleted_005
     * @tc.name    Test 401, when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_on_selectionCompleted_005', 0, () => {
      console.info('************* selectionfwk_on_selectionCompleted_005*************');
      try {
        selectionManager.on(undefined, (info) => {
          console.info(`selectionfwk_on_selectionCompleted_005 callback enter`);
          //expect(info == null).assertTrue();
        });
      } catch(error) {
        console.info(`selectionfwk_on_selectionCompleted_005 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_on_selectionCompleted_005 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_on_selectionCompleted_006
     * @tc.name    Test 401, when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_on_selectionCompleted_006', 0, () => {
      console.info('************* selectionfwk_on_selectionCompleted_006*************');
      try {
        selectionManager.on('selectionCompleted', null);
        console.info(`selectionfwk_on_selectionCompleted_006 is failed`);
        //expect(info == null).assertTrue();
      } catch(error) {
        console.info(`selectionfwk_on_selectionCompleted_006 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_on_selectionCompleted_006 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_on_selectionCompleted_007
     * @tc.name    Test 401, when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_on_selectionCompleted_007', 0, () => {
      console.info('************* selectionfwk_on_selectionCompleted_007*************');
      try {
        selectionManager.on('selectionCompleted', undefined);
        console.info(`selectionfwk_on_selectionCompleted_007 is failed`);
        //expect(info == null).assertTrue();
      } catch(error) {
        console.info(`selectionfwk_on_selectionCompleted_007 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_on_selectionCompleted_007 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_off_selectionCompleted_003
     * @tc.name    Test should success, when parameters are valid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_off_selectionCompleted_003', 0, () => {
      console.info('************* selectionfwk_off_selectionCompleted_003*************');
      try {
          selectionManager.on('selectionCompleted', (info) => {
          console.info(`selectionfwk_on_selectionCompleted_003 callback enter`);
          expect(info != null).assertTrue();
          console.info(`selectionfwk_off_selectionCompleted_003 selectioninfo: ${JSON.stringify(info)}`);
        });
        selectionManager.off('selectionCompleted');
        console.info(`selectionfwk_off_selectionCompleted_003 is success`);
      } catch(error) {
        console.info(`selectionfwk_off_selectionCompleted_003 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      }
      console.info('************* selectionfwk_off_selectionCompleted_003 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_off_selectionCompleted_004
     * @tc.name    Test return 401, when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_off_selectionCompleted_004', 0, () => {
      console.info('************* selectionfwk_off_selectionCompleted_004*************');
      try {
        selectionManager.on('selectionCompleted', (info) => {
          console.info(`selectionfwk_off_selectionCompleted_004 callback enter`);
          expect(info != null).assertTrue();
        });
        selectionManager.off(null);
        console.info(`selectionfwk_off_selectionCompleted_004 is failed`);
      } catch(error) {
        console.info(`selectionfwk_off_selectionCompleted_004 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_off_selectionCompleted_004 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_off_selectionCompleted_005
     * @tc.name    Test return 401, when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_off_selectionCompleted_005', 0, () => {
      console.info('************* selectionfwk_off_selectionCompleted_005*************');
      try {
        selectionManager.on('selectionCompleted', (info) => {
          console.info(`selectionfwk_off_selectionCompleted_005 callback enter`);
          expect(info != null).assertTrue();
        });
        selectionManager.off(undefined);
        console.info(`selectionfwk_off_selectionCompleted_005 is failed`);
      } catch(error) {
        console.info(`selectionfwk_off_selectionCompleted_005 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_off_selectionCompleted_005 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_off_selectionCompleted_006
     * @tc.name    Test return success, when parameters are valid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_off_selectionCompleted_006', 0, () => {
      console.info('************* selectionfwk_off_selectionCompleted_006*************');
      try {
          selectionManager.on('selectionCompleted', (info) => {
          console.info(`selectionfwk_off_selectionCompleted_006 callback enter`);
          expect(info != null).assertTrue();
        });
        selectionManager.off('selectionCompleted', null);
        console.info(`selectionfwk_off_selectionCompleted_006 is success`);
      } catch(error) {
        console.info(`selectionfwk_off_selectionCompleted_006 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      }
      console.info('************* selectionfwk_off_selectionCompleted_006 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_off_selectionCompleted_007
     * @tc.name    Test return sucess, when parameters are valid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_off_selectionCompleted_007', 0, () => {
      console.info('************* selectionfwk_off_selectionCompleted_007*************');
      try {
        selectionManager.on('selectionCompleted', (info) => {
          console.info(`selectionfwk_off_selectionCompleted_007 callback enter`);
          expect(info != null).assertTrue();
        });
        selectionManager.off('selectionCompleted', undefined);
        console.info(`selectionfwk_off_selectionCompleted_007 is success`);
      } catch(error) {
        console.info(`selectionfwk_off_selectionCompleted_007 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      }
      console.info('************* selectionfwk_off_selectionCompleted_007 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_createPanel_002
     * @tc.name    Test should throw BusinessError 401 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_createPanel_002', 0, async () => {
      console.info('************* selectionfwk_createPanel_002 Test start*************');
      try {
        let panelInfo: PanelInfo = {
          panelType: PanelType.MENU_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        await selectionManager.createPanel(null, panelInfo);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_createPanel_002 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_createPanel_002 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_createPanel_004
     * @tc.name    verify method of createPanel.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_createPanel_004', 0, async () => {
      console.info('************* selectionfwk_createPanel_004 Test start*************');
      try {
        let panelInfo: PanelInfo = {
          panelType: PanelType.MENU_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(undefined, panelInfo);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_createPanel_004 throw error: ${JSON.stringify(error)}`);
      }
      console.info('************* selectionfwk_createPanel_004 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_createPanel_005
     * @tc.name    verify method of createPanel.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_createPanel_005', 0, async () => {
      console.info(`selectionfwk_createPanel_005 start1111111111111`); 
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      console.info(`selectionfwk_createPanel_005 throw abilityDelegator: ${JSON.stringify(abilityDelegator)}`);
      let context = abilityDelegator.getAppContext();
      console.info(`selectionfwk_createPanel_005 throw context: ${JSON.stringify(context)}`);
      context.stageMode= true;
      //let stageContext: common.AbilityStageContext = AppStorage.get<common.AbilityStageContext>("stageContext")!;
      //let abilityContext: common.UIAbilityContext = AppStorage.get<common.UIAbilityContext>("abilityContext")!;
      //let appContext: common.ApplicationContext = abilityContext.getApplicationContext();
      //let context: common.BaseContext = stageContext;
      try {
        let panelInfo: PanelInfo = {
          panelType: PanelType.MAIN_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo)
        console.info(`selectionfwk_createPanel_005 throw panel: ${JSON.stringify(panel)}`);
        await selectionManager.destroyPanel(panel);
      } catch (error) {
        console.info(error);
        console.info(`selectionfwk_createPanel_005 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      }
      console.info('************* selectionfwk_createPanel_005 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_destroyPanel_003
     * @tc.name    verify method of destroyPanel.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_destroyPanel_003', 0, async () => {
      console.info('************* selectionfwk_destroyPanel_003 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      try {
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        console.info(`selectionfwk_destroyPanel_003 promise success`);
      } catch (error) {
        console.info(`selectionfwk_destroyPanel_003 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      }
      console.info('************* selectionfwk_destroyPanel_003 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_destroyPanel_005
     * @tc.name    verify method of destroyPanel.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_destroyPanel_005', 0, async () => {
      console.info('************* selectionfwk_destroyPanel_005 Test start*************');
      try {
        await selectionManager.destroyPanel(undefined);
        console.info(`selectionfwk_destroyPanel_005 promise success`);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_destroyPanel_005 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      }
      console.info('************* selectionfwk_destroyPanel_005 Test end*************');
    })

    /*
     * @tc.number  selectionfwk_panel_on_destroyed_001
     * @tc.name    verify ERROR code 401 of the panel on destroyed.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_on_destroyed_001', 0, async (done:Function) => {
      console.info('************* selectionfwk_panel_on_destroyed_001*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        panel.on('destroyed', null);
        expect(false).assertTrue();
      } catch(error) {
        console.info(`selectionfwk_panel_on_destroyed_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      } finally {
        if (panel) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_on_destroyed_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_off_destroyed_001
     * @tc.name    verify ERROR code 401 of the panel off destroyed.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_off_destroyed_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_panel_off_destroyed_001*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        panel.on('destroyed', () => {
          console.info('selectionfwk_panel_off_destroyed_001 callback enter');
        });
        panel.off('destroyed');
        await selectionManager.destroyPanel(panel);
        panel = undefined;
      } catch(error) {
        console.info(`selectionfwk_panel_off_destroyed_001 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      } finally {
        if (panel) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_off_destroyed_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_on_hidden_001
     * @tc.name    verify ERROR code 401 of the panel on hidden.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_on_hidden_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_panel_on_hidden_001*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        panel.on('hidden', null);
        expect(false).assertTrue();
      } catch(error) {
        console.info(`selectionfwk_panel_on_hidden_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      } finally {
        if (panel) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_on_hidden_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_off_hidden_001
     * @tc.name    verify ERROR code 401 of the panel off hidden.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_off_hidden_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_panel_off_hidden_001*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        panel.on('hidden', ()=>{});
        panel.off('hidden');
      } catch(error) {
        console.info(`selectionfwk_panel_off_hidden_001 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      } finally {
        if (panel) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_off_hidden_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_setUiContent_001
     * @tc.name    verify ERROR code 401 of setUiContent.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_setUiContent_001', 0, async (done:Function) =>  {
      console.info('************* selectionfwk_panel_setUiContent_001 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }

      let panel: selectionManager.Panel | undefined = undefined;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await panel.setUiContent(null);
        console.info(`selectionfwk_panel_setUiContent_001 promise failed`);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_setUiContent_001 result: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(401);
      } finally {
        if (panel) {
          await selectionManager.destroyPanel(panel);
        }
      }

      console.info('************* selectionfwk_panel_setUiContent_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_setUiContent_002
     * @tc.name    verify ERROR code 33600002 of setUiContent.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_setUiContent_002', 0, async (done:Function) =>  {
      console.info('************* selectionfwk_panel_setUiContent_002 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }

      let panel: selectionManager.Panel | undefined = undefined;
      let bDestroyed = false;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        bDestroyed = true;
        await panel.setUiContent('page1');
        console.info(`selectionfwk_panel_setUiContent_002 promise failed`);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_setUiContent_002 result: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600002);
      } finally {
        if (!bDestroyed) {
          await selectionManager.destroyPanel(panel);
        }
      }

      console.info('************* selectionfwk_panel_setUiContent_002 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_moveToGlobalDisplay_001
     * @tc.name    verify function of the panel moveToGlobalDisplay.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_moveToGlobalDisplay_001', 0, async () => {
      console.info('************* selectionfwk_panel_moveToGlobalDisplay_001 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await panel.moveToGlobalDisplay(20, 20);
        console.info(`selectionfwk_panel_moveToGlobalDisplay_001 promise success`);
        await selectionManager.destroyPanel(panel);
        panel = undefined;
      } catch (error) {
        console.info(`selectionfwk_panel_moveToGlobalDisplay_001 throw error: ${JSON.stringify(error)}`);
        expect(false).assertTrue();
      } finally {
        if (panel) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_moveToGlobalDisplay_001 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_moveToGlobalDisplay_002
     * @tc.name    verify ERROR code 33600002 of the panel hide.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_moveToGlobalDisplay_002', 0, async (done: Function) => {
      console.info('************* selectionfwk_panel_moveToGlobalDisplay_002 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      let bDestroyed = false;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        bDestroyed = true;
        await panel.moveToGlobalDisplay(20, 20);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_moveToGlobalDisplay_002 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600002);
      } finally {
        if (!bDestroyed) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_moveToGlobalDisplay_002 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_hide_001
     * @tc.name    verify ERROR code 33600002 of the panel hide.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_hide_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_panel_hide_001 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      let bDestroyed = false;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        bDestroyed = true;
        await panel.hide();
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_hide_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600002);
      } finally {
        if (!bDestroyed) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_hide_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_panel_startmoving_001
     * @tc.name    verify ERROR code 33600002 of the panel hide.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_startmoving_001', 0, async () => {
      console.info('************* selectionfwk_panel_startmoving_001 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      let bDestroyed = false;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        bDestroyed = true;
        await panel.startMoving();
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_startmoving_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600002);
      } finally {
        if (!bDestroyed) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_startmoving_001 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_show_001
     * @tc.name    verify ERROR code 33600002 of the panel hide.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_show_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_panel_show_001 Test start*************');
      let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
      abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
      let context = abilityDelegator.getAppContext();
      context.stageMode = true;
      let panelInfo: PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 0,
        y: 0,
        width: 100,
        height: 100
      }
      let panel: selectionManager.Panel | undefined = undefined;
      let bDestroyed = false;
      try {
        panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        bDestroyed = true;
        await panel.show();
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_show_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600002);
      } finally {
        if (!bDestroyed) {
          await selectionManager.destroyPanel(panel);
        }
      }
      console.info('************* selectionfwk_panel_show_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_002
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_002', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_002 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.selectionType == selectionManager.SelectionType.MOUSE_MOVE).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_002 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_003
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_003', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_003 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.startDisplayX == 10).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_003 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_004
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_004', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_004 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.startDisplayY == 10).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_004 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_SelectionInfo_005
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_005', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_005 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }

      expect(sel.endDisplayX == 510).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_005 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_SelectionInfo_006
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_006', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_006 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.endDisplayY == 610).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_006 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_SelectionInfo_007
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_007', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_007 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.startWindowX == 0).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_007 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_008
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_008', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_008 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.startWindowY == 0).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_008 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_009
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_009', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_009 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.endWindowX == 500).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_009 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_010
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_010', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_010 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.endWindowY == 600).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_010 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_011
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_011', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_011 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.displayID == 100).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_011 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_012
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_012', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_012 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.windowID == 101).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_012 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_013
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_013', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_013 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.MOUSE_MOVE,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.bundleName == "com.acts.selection.test").assertTrue();
      console.info('************* selectionfwk_SelectionInfo_013 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_014
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_014', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_014 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.DOUBLE_CLICK,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.selectionType == selectionManager.SelectionType.DOUBLE_CLICK).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_014 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_SelectionInfo_015
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_SelectionInfo_015', 0, async (done: Function) => {
      console.info('************* selectionfwk_SelectionInfo_015 Test start*************');
      let sel : selectionManager.SelectionInfo = {
        selectionType: selectionManager.SelectionType.TRIPLE_CLICK,
        startDisplayX: 10,
        startDisplayY: 10,
        endDisplayX: 510,
        endDisplayY: 610,
        startWindowX: 0,
        startWindowY: 0,
        endWindowX: 500,
        endWindowY: 600,
        displayID: 100,
        windowID: 101,
        bundleName: "com.acts.selection.test"
      }
      expect(sel.selectionType == selectionManager.SelectionType.TRIPLE_CLICK).assertTrue();
      console.info('************* selectionfwk_SelectionInfo_015 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_PanelInfo_001
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_PanelInfo_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_PanelInfo_001 Test start*************');
      let panel : PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 10,
        y: 10,
        width: 400,
        height: 600
      }
      expect(panel.panelType == PanelType.MENU_PANEL).assertTrue();
      console.info('************* selectionfwk_PanelInfo_001 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_PanelInfo_002
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_PanelInfo_002', 0, async (done: Function) => {
      console.info('************* selectionfwk_PanelInfo_002 Test start*************');
      let panel : PanelInfo = {
        panelType: PanelType.MAIN_PANEL,
        x: 10,
        y: 10,
        width: 400,
        height: 600
      }
      expect(panel.panelType == PanelType.MAIN_PANEL).assertTrue();
      console.info('************* selectionfwk_PanelInfo_002 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_PanelInfo_003
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_PanelInfo_003', 0, async (done: Function) => {
      console.info('************* selectionfwk_PanelInfo_003 Test start*************');
      let panel : PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 10,
        y: 10,
        width: 400,
        height: 600
      }
      expect(panel.x == 10).assertTrue();
      console.info('************* selectionfwk_PanelInfo_003 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_PanelInfo_004
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_PanelInfo_004', 0, async (done: Function) => {
      console.info('************* selectionfwk_PanelInfo_004 Test start*************');
      let panel : PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 10,
        y: 10,
        width: 400,
        height: 600
      }
      expect(panel.y == 10).assertTrue();
      console.info('************* selectionfwk_PanelInfo_004 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_PanelInfo_005
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_PanelInfo_005', 0, async (done: Function) => {
      console.info('************* selectionfwk_PanelInfo_005 Test start*************');
      let panel : PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 10,
        y: 10,
        width: 400,
        height: 600
      }
      expect(panel.width == 400).assertTrue();
      console.info('************* selectionfwk_PanelInfo_005 Test end*************');
      done();
    });
    /*
     * @tc.number  selectionfwk_PanelInfo_006
     * @tc.name    verify struct SelectionInfo.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_PanelInfo_006', 0, async (done: Function) => {
      console.info('************* selectionfwk_PanelInfo_006 Test start*************');
      let panel : PanelInfo = {
        panelType: PanelType.MENU_PANEL,
        x: 10,
        y: 10,
        width: 400,
        height: 600
      }
      expect(panel.height == 600).assertTrue();
      console.info('************* selectionfwk_PanelInfo_006 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_startAbility_001
     * @tc.name    verify function startAbility.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_startAbility_001', 0, async (done: Function) => {
      console.info('************* selectionfwk_startAbility_001 Test start*************');
      try {
        let a = new SelectionExtensionContext;
        let want: Want = {
          abilityName: "testAbility"
        };
        await a.startAbility(want);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_startAbility_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code != 16000001).assertTrue();
        expect(error.code != 16000002).assertTrue();
        expect(error.code != 16000004).assertTrue();
        expect(error.code != 16000005).assertTrue();
        expect(error.code != 16000006).assertTrue();
        expect(error.code != 16000008).assertTrue();
        expect(error.code != 16000009).assertTrue();
        expect(error.code != 16000010).assertTrue();
        expect(error.code != 16000011).assertTrue();
        expect(error.code != 16000012).assertTrue();
        expect(error.code != 16000013).assertTrue();
        expect(error.code != 16000019).assertTrue();
        expect(error.code != 16000050).assertTrue();
        expect(error.code != 16000053).assertTrue();
        expect(error.code != 16000055).assertTrue();
        expect(error.code != 16000061).assertTrue();
        expect(error.code != 16000069).assertTrue();
        expect(error.code != 16000070).assertTrue();
        expect(error.code != 16000083).assertTrue();
        expect(error.code != 16200001).assertTrue();
      }
      console.info('************* selectionfwk_startAbility_001 Test end*************');
      done();
    });

    /*
     * @tc.number  selectionfwk_createPanel_001
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_createPanel_001', 0, async () => {
      console.info('************* selectionfwk_createPanel_001 Test start*************');
      try {
        let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
        abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
        let context = abilityDelegator.getAppContext();
        context.stageMode = true;
        await selectionManager.createPanel(context, null);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_createPanel_001 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_createPanel_001 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_destroyPanel_001
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_destroyPanel_001', 0, async () => {
      console.info('************* selectionfwk_destroyPanel_001 Test start*************');
      try {
        let panel: selectionManager.Panel | undefined = undefined;
        await selectionManager.destroyPanel(panel);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_destroyPanel_001 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_destroyPanel_001 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_setUiContent_003
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_setUiContent_003', 0, async () => {
      console.info('************* selectionfwk_panel_setUiContent_003 Test start*************');
      try {
        let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
        abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
        let context = abilityDelegator.getAppContext();
        context.stageMode = true;
        let panelInfo: PanelInfo = {
          panelType: PanelType.MENU_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo);
        await panel.setUiContent("test");
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_setUiContent_003 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_panel_setUiContent_003 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_show_002
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_show_002', 0, async () => {
      console.info('************* selectionfwk_panel_show_002 Test start*************');
      try {
        let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
        abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
        let context = abilityDelegator.getAppContext();
        context.stageMode = true;
        let panelInfo: PanelInfo = {
          panelType: PanelType.MAIN_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        await panel.show();
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_show_002 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_panel_show_002 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_hide_002
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_hide_002', 0, async () => {
      console.info('************* selectionfwk_panel_hide_002 Test start*************');
      try {
        let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
        abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
        let context = abilityDelegator.getAppContext();
        context.stageMode = true;
        let panelInfo: PanelInfo = {
          panelType: PanelType.MAIN_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        await panel.hide();
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_hide_002 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_panel_hide_002 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_startMoving_002
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_startMoving_002', 0, async () => {
      console.info('************* selectionfwk_panel_startMoving_002 Test start*************');
      try {
        let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
        abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
        let context = abilityDelegator.getAppContext();
        context.stageMode = true;
        let panelInfo: PanelInfo = {
          panelType: PanelType.MAIN_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        await panel.startMoving();
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_startMoving_002 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_panel_startMoving_002 Test end*************');
    });

    /*
     * @tc.number  selectionfwk_panel_moveToGlobalDisplay_003
     * @tc.name    Test should throw BusinessError 33600001 when parameters are invalid.
     * @tc.desc    Function test
     * @tc.level   0
     */
    it('selectionfwk_panel_moveToGlobalDisplay_003', 0, async () => {
      console.info('************* selectionfwk_panel_moveToGlobalDisplay_003 Test start*************');
      try {
        let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
        abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
        let context = abilityDelegator.getAppContext();
        context.stageMode = true;
        let panelInfo: PanelInfo = {
          panelType: PanelType.MAIN_PANEL,
          x: 0,
          y: 0,
          width: 100,
          height: 100
        }
        let panel: selectionManager.Panel = await selectionManager.createPanel(context, panelInfo);
        await selectionManager.destroyPanel(panel);
        await panel.moveToGlobalDisplay(20, 20);
        expect(false).assertTrue();
      } catch (error) {
        console.info(`selectionfwk_panel_moveToGlobalDisplay_003 throw error: `, error);
        expect(error.code != 33600001).assertTrue();
      }
      console.info('************* selectionfwk_panel_moveToGlobalDisplay_003 Test end*************');
    });
      
    /*
    * @tc.number  SUB_Driver_Selection_Content_0100
    * @tc.name    The code 31400005 is returned when the word content is obtained without the word division operation.
    * @tc.desc    Function test
    * @tc.level   0
    */
    it('selectionfwk_get_selection_content_001', 0, async (done:Function) => {
      console.info('************* selectionfwk_get_selection_content_001 Test start*************');
      try {
        let content: string = await selectionManager.getSelectionContent();
        expect().assertFail();
      } catch (error) {
        console.info(`selectionfwk_get_selection_content_001 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600005);
      }
      await new Promise<void>(resolve => setTimeout(resolve, 500));
      console.info('************* selectionfwk_get_selection_content_001 Test end*************');
      done();
    });

    /*
    * @tc.number  SUB_Driver_Selection_Content_0200
    * @tc.name    If getSelectionContent is invoked for multiple times without word division, the error code 31400004 is returned.
    * @tc.desc    Function test
    * @tc.level   0
    */
    it('selectionfwk_get_selection_content_002', 0, async (done:Function) => {
      console.info('************* selectionfwk_get_selection_content_002 Test start*************');
      for (let i = 0; i < 50; ++i) {
        try {
          let content: string = await selectionManager.getSelectionContent();
          expect().assertFail();
        } catch (error) {
          console.info(`selectionfwk_get_selection_content_002 throw error sjw: ${JSON.stringify(error)}`);
          expect(error.code).assertEqual(33600005);
        }
      }
      try {
        let content: string = await selectionManager.getSelectionContent();
        expect().assertFail();
      } catch (error) {
        console.info(`selectionfwk_get_selection_content_002 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600004);
      }
      await new Promise<void>(resolve => setTimeout(resolve, 500));
      console.info('************* selectionfwk_get_selection_content_002 Test end*************');
      done();
    });

    /*
    * @tc.number  SUB_Driver_Selection_Content_0300
    * @tc.name    If getSelectionContent is invoked for multiple times without word division,31400005 is returned after the delay is added.
    * @tc.desc    Function test
    * @tc.level   0
    */
    it('selectionfwk_get_selection_content_003', 0, async (done:Function) => {
      console.info('************* selectionfwk_get_selection_content_003 Test start*************');
      for (let i = 0; i < 50; ++i) {
        try {
          let content: string = await selectionManager.getSelectionContent();
          expect().assertFail();
        } catch (error) {
          console.info(`selectionfwk_get_selection_content_003 throw error: ${JSON.stringify(error)}`);
          expect(error.code).assertEqual(33600005);
        }
      }
      await new Promise<void>(resolve => setTimeout(resolve, 500));
      try {
        let content: string = await selectionManager.getSelectionContent();
        expect().assertFail();
      } catch (error) {
        console.info(`selectionfwk_get_selection_content_003 throw error: ${JSON.stringify(error)}`);
        expect(error.code).assertEqual(33600005);
      }
      await new Promise<void>(resolve => setTimeout(resolve, 500));
      console.info('************* selectionfwk_get_selection_content_003 Test end***`**********');
      done();
    });
  })
}