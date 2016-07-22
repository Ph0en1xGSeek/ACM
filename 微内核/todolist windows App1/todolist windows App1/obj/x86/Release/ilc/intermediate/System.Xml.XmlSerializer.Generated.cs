namespace System.Runtime.CompilerServices {
    internal class __BlockReflectionAttribute : Attribute { }
}

namespace Microsoft.Xml.Serialization.GeneratedAssembly {


    [System.Runtime.CompilerServices.__BlockReflection]
    public class XmlSerializationWriter1 : System.Xml.Serialization.XmlSerializationWriter {

        public void Write6_ArrayOfEvents(object o, string parentRuntimeNs = null, string parentCompileTimeNs = null) {
            string defaultNamespace = parentRuntimeNs ?? @"";
            WriteStartDocument();
            if (o == null) {
                WriteNullTagLiteral(@"ArrayOfEvents", defaultNamespace);
                return;
            }
            TopLevelElement();
            string namespace1 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            {
                global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events> a = (global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>)((global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>)o);
                if ((object)(a) == null) {
                    WriteNullTagLiteral(@"ArrayOfEvents", defaultNamespace);
                }
                else {
                    WriteStartElement(@"ArrayOfEvents", namespace1, null, false);
                    for (int ia = 0; ia < ((System.Collections.ICollection)a).Count; ia++) {
                        string namespace2 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
                        Write5_events(@"events", namespace2, ((global::todolist_windows_App1.events)a[ia]), true, false, namespace2, @"");
                    }
                    WriteEndElement();
                }
            }
        }

        void Write5_events(string n, string ns, global::todolist_windows_App1.events o, bool isNullable, bool needType, string parentRuntimeNs = null, string parentCompileTimeNs = null) {
            string defaultNamespace = parentRuntimeNs;
            if ((object)o == null) {
                if (isNullable) WriteNullTagLiteral(n, ns);
                return;
            }
            if (!needType) {
                System.Type t = o.GetType();
                if (t == typeof(global::todolist_windows_App1.events)) {
                }
                else {
                    throw CreateUnknownTypeException(o);
                }
            }
            WriteStartElement(n, ns, o, false, null);
            if (needType) WriteXsiType(@"events", defaultNamespace);
            string namespace3 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            WriteElementString(@"uri", namespace3, ((global::System.String)o.@uri));
            string namespace4 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            WriteElementString(@"date", namespace4, ((global::System.String)o.@date));
            string namespace5 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            WriteElementString(@"detail", namespace5, ((global::System.String)o.@detail));
            string namespace6 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            WriteElementString(@"description", namespace6, ((global::System.String)o.@description));
            string namespace7 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            WriteElementStringRaw(@"IsChecked", namespace7, System.Xml.XmlConvert.ToString((global::System.Boolean)((global::System.Boolean)o.@IsChecked)));
            string namespace8 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            Write3_DateTimeOffset(@"realdate", namespace8, ((global::System.DateTimeOffset)o.@realdate), false, namespace8, @"");
            string namespace9 = ( parentCompileTimeNs == @"" && parentRuntimeNs != null ) ? parentRuntimeNs : @"";
            Write4_TimeSpan(@"time", namespace9, ((global::System.TimeSpan)o.@time), false, namespace9, @"");
            WriteEndElement(o);
        }

        void Write4_TimeSpan(string n, string ns, global::System.TimeSpan o, bool needType, string parentRuntimeNs = null, string parentCompileTimeNs = null) {
            string defaultNamespace = parentRuntimeNs;
            if (!needType) {
                System.Type t = o.GetType();
                if (t == typeof(global::System.TimeSpan)) {
                }
                else {
                    throw CreateUnknownTypeException(o);
                }
            }
            WriteStartElement(n, ns, o, false, null);
            if (needType) WriteXsiType(@"TimeSpan", defaultNamespace);
            WriteEndElement(o);
        }

        void Write3_DateTimeOffset(string n, string ns, global::System.DateTimeOffset o, bool needType, string parentRuntimeNs = null, string parentCompileTimeNs = null) {
            string defaultNamespace = parentRuntimeNs;
            if (!needType) {
                System.Type t = o.GetType();
                if (t == typeof(global::System.DateTimeOffset)) {
                }
                else {
                    throw CreateUnknownTypeException(o);
                }
            }
            WriteStartElement(n, ns, o, false, null);
            if (needType) WriteXsiType(@"DateTimeOffset", defaultNamespace);
            WriteEndElement(o);
        }

        protected override void InitCallbacks() {
        }
    }

    [System.Runtime.CompilerServices.__BlockReflection]
    public class XmlSerializationReader1 : System.Xml.Serialization.XmlSerializationReader {

        public object Read6_ArrayOfEvents(string defaultNamespace = null) {
            object o = null;
            Reader.MoveToContent();
            if (Reader.NodeType == System.Xml.XmlNodeType.Element) {
                if (((object) Reader.LocalName == (object)id1_ArrayOfEvents && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                    if (!ReadNull()) {
                        if ((object)(o) == null) o = new global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>();
                        global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events> a_0_0 = (global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>)o;
                        if ((Reader.IsEmptyElement)) {
                            Reader.Skip();
                        }
                        else {
                            Reader.ReadStartElement();
                            Reader.MoveToContent();
                            int whileIterations0 = 0;
                            int readerCount0 = ReaderCount;
                            while (Reader.NodeType != System.Xml.XmlNodeType.EndElement && Reader.NodeType != System.Xml.XmlNodeType.None) {
                                if (Reader.NodeType == System.Xml.XmlNodeType.Element) {
                                    if (((object) Reader.LocalName == (object)id3_events && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                                        if ((object)(a_0_0) == null) Reader.Skip(); else a_0_0.Add(Read5_events(true, true, defaultNamespace));
                                    }
                                    else {
                                        UnknownNode(null, @":events");
                                    }
                                }
                                else {
                                    UnknownNode(null, @":events");
                                }
                                Reader.MoveToContent();
                                CheckReaderCount(ref whileIterations0, ref readerCount0);
                            }
                        ReadEndElement();
                        }
                    }
                    else {
                        if ((object)(o) == null) o = new global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>();
                        global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events> a_0_0 = (global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>)o;
                    }
                }
                else {
                    throw CreateUnknownNodeException();
                }
            }
            else {
                UnknownNode(null, defaultNamespace ?? @":ArrayOfEvents");
            }
            return (object)o;
        }

        global::todolist_windows_App1.events Read5_events(bool isNullable, bool checkType, string defaultNamespace = null) {
            System.Xml.XmlQualifiedName xsiType = checkType ? GetXsiType() : null;
            bool isNull = false;
            if (isNullable) isNull = ReadNull();
            if (checkType) {
            if (xsiType == null || ((object) ((System.Xml.XmlQualifiedName)xsiType).Name == (object)id3_events && string.Equals( ((System.Xml.XmlQualifiedName)xsiType).Namespace, defaultNamespace ?? id2_Item))) {
            }
            else
                throw CreateUnknownTypeException((System.Xml.XmlQualifiedName)xsiType);
            }
            if (isNull) return null;
            global::todolist_windows_App1.events o;
            o = new global::todolist_windows_App1.events();
            bool[] paramsRead = new bool[7];
            while (Reader.MoveToNextAttribute()) {
                if (!IsXmlnsAttribute(Reader.Name)) {
                    UnknownNode((object)o);
                }
            }
            Reader.MoveToElement();
            if (Reader.IsEmptyElement) {
                Reader.Skip();
                return o;
            }
            Reader.ReadStartElement();
            Reader.MoveToContent();
            int whileIterations1 = 0;
            int readerCount1 = ReaderCount;
            while (Reader.NodeType != System.Xml.XmlNodeType.EndElement && Reader.NodeType != System.Xml.XmlNodeType.None) {
                if (Reader.NodeType == System.Xml.XmlNodeType.Element) {
                    if (!paramsRead[0] && ((object) Reader.LocalName == (object)id4_uri && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        {
                            o.@uri = Reader.ReadElementContentAsString();
                        }
                        paramsRead[0] = true;
                    }
                    else if (!paramsRead[1] && ((object) Reader.LocalName == (object)id5_date && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        {
                            o.@date = Reader.ReadElementContentAsString();
                        }
                        paramsRead[1] = true;
                    }
                    else if (!paramsRead[2] && ((object) Reader.LocalName == (object)id6_detail && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        {
                            o.@detail = Reader.ReadElementContentAsString();
                        }
                        paramsRead[2] = true;
                    }
                    else if (!paramsRead[3] && ((object) Reader.LocalName == (object)id7_description && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        {
                            o.@description = Reader.ReadElementContentAsString();
                        }
                        paramsRead[3] = true;
                    }
                    else if (!paramsRead[4] && ((object) Reader.LocalName == (object)id8_IsChecked && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        {
                            o.@IsChecked = System.Xml.XmlConvert.ToBoolean(Reader.ReadElementContentAsString());
                        }
                        paramsRead[4] = true;
                    }
                    else if (!paramsRead[5] && ((object) Reader.LocalName == (object)id9_realdate && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        o.@realdate = Read3_DateTimeOffset(true, defaultNamespace);
                        paramsRead[5] = true;
                    }
                    else if (!paramsRead[6] && ((object) Reader.LocalName == (object)id10_time && string.Equals(Reader.NamespaceURI, defaultNamespace ?? id2_Item))) {
                        o.@time = Read4_TimeSpan(true, defaultNamespace);
                        paramsRead[6] = true;
                    }
                    else {
                        UnknownNode((object)o, @":uri, :date, :detail, :description, :IsChecked, :realdate, :time");
                    }
                }
                else {
                    UnknownNode((object)o, @":uri, :date, :detail, :description, :IsChecked, :realdate, :time");
                }
                Reader.MoveToContent();
                CheckReaderCount(ref whileIterations1, ref readerCount1);
            }
            ReadEndElement();
            return o;
        }

        global::System.TimeSpan Read4_TimeSpan(bool checkType, string defaultNamespace = null) {
            System.Xml.XmlQualifiedName xsiType = checkType ? GetXsiType() : null;
            bool isNull = false;
            if (checkType) {
            if (xsiType == null || ((object) ((System.Xml.XmlQualifiedName)xsiType).Name == (object)id11_TimeSpan && string.Equals( ((System.Xml.XmlQualifiedName)xsiType).Namespace, defaultNamespace ?? id2_Item))) {
            }
            else
                throw CreateUnknownTypeException((System.Xml.XmlQualifiedName)xsiType);
            }
            global::System.TimeSpan o;
            try {
                o = (global::System.TimeSpan)ActivatorHelper.CreateInstance(typeof(global::System.TimeSpan));
            }
            catch (System.MissingMemberException) {
                throw CreateInaccessibleConstructorException(@"global::System.TimeSpan");
            }
            catch (System.Security.SecurityException) {
                throw CreateCtorHasSecurityException(@"global::System.TimeSpan");
            }
            bool[] paramsRead = new bool[0];
            while (Reader.MoveToNextAttribute()) {
                if (!IsXmlnsAttribute(Reader.Name)) {
                    UnknownNode((object)o);
                }
            }
            Reader.MoveToElement();
            if (Reader.IsEmptyElement) {
                Reader.Skip();
                return o;
            }
            Reader.ReadStartElement();
            Reader.MoveToContent();
            int whileIterations2 = 0;
            int readerCount2 = ReaderCount;
            while (Reader.NodeType != System.Xml.XmlNodeType.EndElement && Reader.NodeType != System.Xml.XmlNodeType.None) {
                if (Reader.NodeType == System.Xml.XmlNodeType.Element) {
                    UnknownNode((object)o, @"");
                }
                else {
                    UnknownNode((object)o, @"");
                }
                Reader.MoveToContent();
                CheckReaderCount(ref whileIterations2, ref readerCount2);
            }
            ReadEndElement();
            return o;
        }

        global::System.DateTimeOffset Read3_DateTimeOffset(bool checkType, string defaultNamespace = null) {
            System.Xml.XmlQualifiedName xsiType = checkType ? GetXsiType() : null;
            bool isNull = false;
            if (checkType) {
            if (xsiType == null || ((object) ((System.Xml.XmlQualifiedName)xsiType).Name == (object)id12_DateTimeOffset && string.Equals( ((System.Xml.XmlQualifiedName)xsiType).Namespace, defaultNamespace ?? id2_Item))) {
            }
            else
                throw CreateUnknownTypeException((System.Xml.XmlQualifiedName)xsiType);
            }
            global::System.DateTimeOffset o;
            try {
                o = (global::System.DateTimeOffset)ActivatorHelper.CreateInstance(typeof(global::System.DateTimeOffset));
            }
            catch (System.MissingMemberException) {
                throw CreateInaccessibleConstructorException(@"global::System.DateTimeOffset");
            }
            catch (System.Security.SecurityException) {
                throw CreateCtorHasSecurityException(@"global::System.DateTimeOffset");
            }
            bool[] paramsRead = new bool[0];
            while (Reader.MoveToNextAttribute()) {
                if (!IsXmlnsAttribute(Reader.Name)) {
                    UnknownNode((object)o);
                }
            }
            Reader.MoveToElement();
            if (Reader.IsEmptyElement) {
                Reader.Skip();
                return o;
            }
            Reader.ReadStartElement();
            Reader.MoveToContent();
            int whileIterations3 = 0;
            int readerCount3 = ReaderCount;
            while (Reader.NodeType != System.Xml.XmlNodeType.EndElement && Reader.NodeType != System.Xml.XmlNodeType.None) {
                if (Reader.NodeType == System.Xml.XmlNodeType.Element) {
                    UnknownNode((object)o, @"");
                }
                else {
                    UnknownNode((object)o, @"");
                }
                Reader.MoveToContent();
                CheckReaderCount(ref whileIterations3, ref readerCount3);
            }
            ReadEndElement();
            return o;
        }

        protected override void InitCallbacks() {
        }

        string id6_detail;
        string id1_ArrayOfEvents;
        string id4_uri;
        string id12_DateTimeOffset;
        string id10_time;
        string id5_date;
        string id11_TimeSpan;
        string id8_IsChecked;
        string id7_description;
        string id2_Item;
        string id3_events;
        string id9_realdate;

        protected override void InitIDs() {
            id6_detail = Reader.NameTable.Add(@"detail");
            id1_ArrayOfEvents = Reader.NameTable.Add(@"ArrayOfEvents");
            id4_uri = Reader.NameTable.Add(@"uri");
            id12_DateTimeOffset = Reader.NameTable.Add(@"DateTimeOffset");
            id10_time = Reader.NameTable.Add(@"time");
            id5_date = Reader.NameTable.Add(@"date");
            id11_TimeSpan = Reader.NameTable.Add(@"TimeSpan");
            id8_IsChecked = Reader.NameTable.Add(@"IsChecked");
            id7_description = Reader.NameTable.Add(@"description");
            id2_Item = Reader.NameTable.Add(@"");
            id3_events = Reader.NameTable.Add(@"events");
            id9_realdate = Reader.NameTable.Add(@"realdate");
        }
    }

    [System.Runtime.CompilerServices.__BlockReflection]
    public abstract class XmlSerializer1 : System.Xml.Serialization.XmlSerializer {
        protected override System.Xml.Serialization.XmlSerializationReader CreateReader() {
            return new XmlSerializationReader1();
        }
        protected override System.Xml.Serialization.XmlSerializationWriter CreateWriter() {
            return new XmlSerializationWriter1();
        }
    }

    [System.Runtime.CompilerServices.__BlockReflection]
    public sealed class ObservableCollectionOfeventsSerializer : XmlSerializer1 {

        public override System.Boolean CanDeserialize(System.Xml.XmlReader xmlReader) {
            return xmlReader.IsStartElement(@"ArrayOfEvents", this.DefaultNamespace ?? @"");
        }

        protected override void Serialize(object objectToSerialize, System.Xml.Serialization.XmlSerializationWriter writer) {
            ((XmlSerializationWriter1)writer).Write6_ArrayOfEvents(objectToSerialize, this.DefaultNamespace, @"");
        }

        protected override object Deserialize(System.Xml.Serialization.XmlSerializationReader reader) {
            return ((XmlSerializationReader1)reader).Read6_ArrayOfEvents(this.DefaultNamespace);
        }
    }

    [System.Runtime.CompilerServices.__BlockReflection]
    public class XmlSerializerContract : global::System.Xml.Serialization.XmlSerializerImplementation {
        public override global::System.Xml.Serialization.XmlSerializationReader Reader { get { return new XmlSerializationReader1(); } }
        public override global::System.Xml.Serialization.XmlSerializationWriter Writer { get { return new XmlSerializationWriter1(); } }
        System.Collections.IDictionary readMethods = null;
        public override System.Collections.IDictionary ReadMethods {
            get {
                if (readMethods == null) {
                    System.Collections.IDictionary _tmp = new System.Collections.Generic.Dictionary<string, string>();
                    _tmp[@"System.Collections.ObjectModel.ObservableCollection`1[[todolist_windows_App1.events, todolist windows App1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]]::"] = @"Read6_ArrayOfEvents";
                    if (readMethods == null) readMethods = _tmp;
                }
                return readMethods;
            }
        }
        System.Collections.IDictionary writeMethods = null;
        public override System.Collections.IDictionary WriteMethods {
            get {
                if (writeMethods == null) {
                    System.Collections.IDictionary _tmp = new System.Collections.Generic.Dictionary<string, string>();
                    _tmp[@"System.Collections.ObjectModel.ObservableCollection`1[[todolist_windows_App1.events, todolist windows App1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]]::"] = @"Write6_ArrayOfEvents";
                    if (writeMethods == null) writeMethods = _tmp;
                }
                return writeMethods;
            }
        }
        System.Collections.IDictionary typedSerializers = null;
        public override System.Collections.IDictionary TypedSerializers {
            get {
                if (typedSerializers == null) {
                    System.Collections.IDictionary _tmp = new System.Collections.Generic.Dictionary<string, System.Xml.Serialization.XmlSerializer>();
                    _tmp.Add(@"System.Collections.ObjectModel.ObservableCollection`1[[todolist_windows_App1.events, todolist windows App1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]]::", new ObservableCollectionOfeventsSerializer());
                    if (typedSerializers == null) typedSerializers = _tmp;
                }
                return typedSerializers;
            }
        }
        public override System.Boolean CanSerialize(System.Type type) {
            if (type == typeof(global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>)) return true;
            if (type == typeof(global::System.Reflection.TypeInfo)) return true;
            return false;
        }
        public override System.Xml.Serialization.XmlSerializer GetSerializer(System.Type type) {
            if (type == typeof(global::System.Collections.ObjectModel.ObservableCollection<global::todolist_windows_App1.events>)) return new ObservableCollectionOfeventsSerializer();
            return null;
        }
        public static global::System.Xml.Serialization.XmlSerializerImplementation GetXmlSerializerContract() { return new XmlSerializerContract(); }
    }

    [System.Runtime.CompilerServices.__BlockReflection]
    public static class ActivatorHelper {
        public static object CreateInstance(System.Type type) {
            System.Reflection.TypeInfo ti = System.Reflection.IntrospectionExtensions.GetTypeInfo(type);
            foreach (System.Reflection.ConstructorInfo ci in ti.DeclaredConstructors) {
                if (!ci.IsStatic && ci.GetParameters().Length == 0) {
                    return ci.Invoke(null);
                }
            }
            return System.Activator.CreateInstance(type);
        }
    }
}
